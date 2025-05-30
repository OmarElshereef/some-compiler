
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstring>
    #include "utils/symbolTable.hpp"
    #include "utils/quadHandler.hpp"
    #include "utils/ErrorManger.cpp"
    #pragma once
    symbolTable symbTable = symbolTable();
    QuadHandler quadHandle = QuadHandler("output/quad.txt");
    ErrorManager errorManager ;
    int symbolTable::numScopes = 0;
    vector<vector<symbolTable*>> symbolTable::symbolTableAdj = vector<vector<symbolTable*>>(1,vector<symbolTable*>());
    symbolTable* symbolTable::current = &symbTable;
    map<string, vector<symbol*>> functionParameters;
    vector<symbol*> currentFunctionParameters;
    vector<symbol*> functionCallParameters;
    symbolType currFunctionReturn = symbolType::UNKNOWN;
    string currSwitchLabel = "";
    symbol* currSwitchVar = NULL;
    int yylex();
    extern char *yytext;
    extern int yylineno;

    int inFunction = 0;
    bool hasReturn = false;
    %}

%union {
    char *sval;
    symbol* symboll;
    symbolType symbolTypeType;
    LoopLabels* loopLabels;
    operation operationName;
}

/* Keywords */
%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT BREAK CONTINUE RETURN

/* Data types */
%token CONST INT FLOAT CHAR DOUBLE VOID STRING BOOL LINT LLINT

/* Boolean values */
%token TRUE FALSE

/* Mathematical operators */
%token PLUS MINUS MUL DIV MOD INC DEC

/* Assignment operators */
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

/* Relational operators */
%token EQ NEQ LT GT LTE GTE

/* Logical operators */
%token AND OR NOT

/* Bitwise operators */
%token BIT_AND BIT_OR BIT_XOR

/* COMMENT tokens */
%token COMMENT

/* Associativity: https://en.cppreference.com/w/cpp/language/operator_precedence */
%right  ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left   OR
%left   AND
%left   BIT_XOR
%left   BIT_OR
%left   BIT_AND
%left   EQ NEQ
%left   LT GT LTE GTE
%left   PLUS MINUS
%left   MUL DIV MOD
%right  NOT
%left   INC DEC
//%left   FUNC

%nonassoc ELSE
%nonassoc LOWER_THAN_ELSE


/* Other tokens */
%token <sval> ID
%token <sval> LLINT_CONST LINT_CONST FLOAT_CONST DOUBLE_CONST INT_CONST
%token <sval> STRING_CONST CHAR_CONST

%type <sval> function_declaration_prototype
//%type <symboll> evaluate_expression 
%type <symboll> expression
%type <symboll> unary_expression
%type <symboll> literal
%type <symboll> assignment
%type <symboll> for_loop_condition
//%type <symboll> initialization
%type <loopLabels> while_prefix
%type <sval> start_declaration start_initialization declaration_initialization
%type <loopLabels> while_label
%type <symboll> function_call
%type <symbolTypeType> type 
//%type <operationName> assign



/* Grammar */
%%

program :
        program statement       {;}
        |                       {;}
        ;

statement :
        matched_statement  {;}
        | 
        unmatched_statement {;}
        |
        error sync_token {
        yyerrok;
    }

sync_token: ';' | '}' | '\n' ;


if_condition_action:
    '(' expression ')' {
        string tempLabel = quadHandle.generateLabel();
        quadHandle.tempLabels.push_back(tempLabel);
        quadHandle.jump_cond_op($2, tempLabel.c_str(), false);
    }
    ;

if_body_action:
    {
        string endLabel = quadHandle.tempLabels.back();
        quadHandle.tempLabels.pop_back();
        string elseLabel = quadHandle.generateLabel();
        quadHandle.tempLabels.push_back(elseLabel);
        quadHandle.writeToFile("jmp " + elseLabel);
        quadHandle.writeToFile(endLabel + ":"); 
    }
    ;

else_end_action:
    {
        string endLabel = quadHandle.tempLabels.back();
        quadHandle.tempLabels.pop_back();
        quadHandle.writeToFile(endLabel + ":");
    }
    ;

matched_statement :
        IF if_condition_action matched_statement if_body_action ELSE matched_statement else_end_action
        | other_stmt {;}
        ;

unmatched_statement :
        IF if_condition_action matched_statement %prec LOWER_THAN_ELSE else_end_action
        |
        IF if_condition_action matched_statement if_body_action ELSE unmatched_statement else_end_action
        ;

other_stmt :
        start_declaration ';'             { printf("Declaration\n"); }
        | 
        start_initialization ';'        { printf("Initialization\n"); }
        | 
        assignment ';'            { printf("Assignment\n"); }
        | 
        expression ';'      { printf("Expression\n"); }
        | 
        switch_statement          { printf("Switch case end\n"); }
        | 
        do_loop ';'               { printf("Do while loop end\n"); }
        | 
        while_loop                { printf("While loop end\n"); }
        | 
        for_loop                  { printf("For loop end\n"); }
        | 
        function_definition       { printf("Function_definition end\n"); }
        |
        return_statement ';' { printf("Return statement end\n"); }
        | 
        '{' {symbTable.changeScope(1);} program '}' {symbTable.changeScope(0);}    { printf("Scope end\n"); }
        ;

start_initialization
    : type ID ASSIGN expression {
            symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            symbolTable::currentType = $1;
            symbolTable::isCurrentConst = false;
            symbol* sym = symbolTable::current->addSymbol($2, $1, false, true);
            if (sym != NULL) {
                quadHandle.assign_op(operation::Assign, sym, $4);
            }
    } declaration_initialization
    |
    CONST type ID ASSIGN expression {
            symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            symbolTable::currentType = $2;
            symbolTable::isCurrentConst = true;
            printf("Initialization on %s\n", $3);
            symbol* sym = symbolTable::current->addSymbol($3, $2, true, true);
            if (sym != NULL) {
                quadHandle.assign_op(operation::Assign, sym, $5);
            }
    } declaration_initialization
    ;

start_declaration
    : type ID {
            symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            symbolTable::currentType = $1;
            symbolTable::isCurrentConst = false;
            symbol* sym = symbolTable::current->addSymbol($2, $1, false, false);
            if (!sym) printf("initialization error\n");
        } declaration_initialization
    ;

declaration_initialization
    : ',' ID {
            symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            symbol* sym = symbolTable::current->addSymbol($2, symbolTable::currentType, symbolTable::isCurrentConst, true);
            if (!sym) yyerror("initialization error\n");
        } declaration_initialization
    | 
    ',' ID ASSIGN expression {
            symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            symbol* sym = symbolTable::current->addSymbol($2, symbolTable::currentType, symbolTable::isCurrentConst, true);
            if (sym != NULL) {
                quadHandle.assign_op(operation::Assign, sym, $4);
            }
        } declaration_initialization
    |
    {;}
    ;

function_definition
    : function_declaration_prototype {
        if (inFunction) {
            errorManager.add(SEMANTIC, yylineno, yytext, "You cannot declare a function inside a function.");
            YYABORT;
        }
        inFunction = 1;
    }
    '{' program  '}' {
        if(hasReturn == false && currFunctionReturn != symbolType::VOIDtype) {
            errorManager.add(SEMANTIC, yylineno, yytext, "Function must return a value.");
        }
        hasReturn = false;
        inFunction = 0;
        symbTable.changeScope(0);
        functionParameters[$1] = currentFunctionParameters;
        currentFunctionParameters.clear();
        currFunctionReturn = symbolType::UNKNOWN;
    }
;

function_declaration_prototype
    : VOID ID {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        if (inFunction) {
            errorManager.add(SEMANTIC, yylineno, yytext, "You cannot declare a function inside a function.");
            YYABORT;
        }
        symbol* funName = symbTable.addSymbol(string($2), symbolType::VOIDtype, 0, 1);
        if (funName == NULL) {
            funName = new symbol($2, symbolType::ERROR, 1, 1);
        }
        symbTable.setUsed(funName);
        symbTable.changeScope(1);
        currFunctionReturn = symbolType::VOIDtype;
    }
    '(' function_parameters_optional ')' {
        quadHandle.declare_func_op(symbTable.findSymbol(string($2)), currentFunctionParameters);
        $$ = $2;  
    }
    
    | type ID {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        if (inFunction) {
            errorManager.add(SEMANTIC, yylineno, yytext, "You cannot declare a function inside a function.");
            YYABORT;
        }
        symbol* funName = symbTable.addSymbol(string($2), $1, 0, 1);
        if (funName == NULL) {
            funName = new symbol($2, symbolType::ERROR, 1, 1);
        }
        symbTable.setUsed(funName);
        symbTable.changeScope(1);
        currFunctionReturn = $1;
    }
    '(' function_parameters_optional ')' {
        quadHandle.declare_func_op(symbTable.findSymbol(string($2)), currentFunctionParameters);
        $$ = $2;  
    }
;


function_parameters_optional :
    function_parameters             {;}
    |
                                    {;}
    ;

function_parameters :
    function_parameters ',' function_parameter      {;}
    |
    function_parameter                              {;}
    ;

function_parameter:
    type ID             {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* s = symbTable.addSymbol(string($2),$1,0,1);
        if (s == NULL) {
            s = new symbol($2, symbolType::ERROR, 1,1);
        }
        currentFunctionParameters.push_back(s);
     } 
    ;

return_statement :
    RETURN expression   {symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            if(inFunction == 0) {
                errorManager.add(SEMANTIC, yylineno, yytext, "Return statement outside of function.");
            }
            printf("function return type: %d\n", currFunctionReturn);
            printf("expression type: %d\n", $2->type);
            if(currFunctionReturn !=$2->type) {
                errorManager.add(SEMANTIC, yylineno, yytext, "Function return type mismatch.");
            }
            hasReturn = true;
            quadHandle.return_op($2, currFunctionReturn);
            }
    |
    RETURN              {symbTable.lineNumber = yylineno;
            quadHandle.lineNumber = yylineno;
            if(inFunction == 0) {
                errorManager.add(SEMANTIC, yylineno, yytext, "Return statement outside of function.");
            }
            hasReturn = true;
            quadHandle.return_op(NULL, currFunctionReturn);
            }
    ;

function_call : 
    ID '(' function_arguments_optional ')' {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* temp = symbTable.useSymbol(string($1));
        if (temp == NULL) {
            temp = new symbol($1, symbolType::ERROR, 1,1);
            errorManager.add(SEMANTIC, yylineno, yytext, "Function not declared.");
        }
        else{
            if (!functionParameters.count(string(temp->name))) {
            errorManager.add(SEMANTIC, yylineno, yytext, "Function not declared.");
        }
        vector<symbol*> params = functionParameters[string(temp->name)];
        if (params.size() != functionCallParameters.size()) {
            errorManager.add(SEMANTIC, yylineno, yytext, "Parameter count mismatch.");
        }
        for (int i = 0; i < params.size(); i++) {
            if (!quadHandle.tryCast(functionCallParameters[i], params[i]->type)) {
                errorManager.add(SEMANTIC, yylineno, yytext, "Parameter type mismatch.");
            }
        }
        }
        symbol* ret = quadHandle.call_func_op(temp, functionCallParameters);
        functionCallParameters.clear();
        $$ = ret;
    };
    
function_arguments_optional :
    function_arguments      {;}
    |
                            {;}
    ;

function_arguments :
    function_arguments ',' function_argument    {;}
    |
    function_argument                           {;}
    ;

function_argument :
    literal            {functionCallParameters.push_back($1);}
    ;

do_loop :
        DO {symbTable.changeScope(1); string label = quadHandle.generateLabel(); quadHandle.writeToFile(label+":"); $<sval>$ = strdup(label.data());} 
           '{' program '}' 
           WHILE 
           {symbTable.changeScope(0);} 
           '(' expression ')'      {quadHandle.jump_cond_op($9, $<sval>2, true);}
        ;

for_loop :
        FOR {   symbTable.changeScope(1); 
                string label = quadHandle.generateLabel(); 
                $<sval>$ = strdup(label.data());} 
            '(' for_loop_initialization {quadHandle.writeToFile(string($<sval>2)+":");} ';' 
            for_loop_condition {
                string label = quadHandle.generateLabel(); 
                $<sval>$ = strdup(label.data()); 
                quadHandle.jump_cond_op($7, label, false);} ';' 
            for_loop_increment ')' 
            '{' program '}' 
            {   quadHandle.jump_uncond_op($<sval>2); 
                symbTable.changeScope(0); 
                quadHandle.writeToFile(string($<sval>8) + ":");};
        ;

for_loop_initialization :
    INT ID ASSIGN INT_CONST {
                                symbTable.lineNumber = yylineno;
                                quadHandle.lineNumber = yylineno;
                                symbol* temp = symbTable.addSymbol(string($2), symbolType::INTtype, 0, 1);
                                if(temp == NULL) {
                                    temp = new symbol($2, symbolType::ERROR, 1,1);
                                }
                                quadHandle.assign_op(operation::Assign, temp, new symbol($4, symbolType::INTtype, 1,1));
                            }
    |
    ID ASSIGN INT_CONST     {
                                symbTable.lineNumber = yylineno;
                                quadHandle.lineNumber = yylineno;
                                symbol* temp = symbTable.updateSymbol(string($1));

                                quadHandle.assign_op(operation::Assign, temp, new symbol($3, symbolType::INTtype, 1,1));
                            }
    |
    ID                      {
                                symbTable.lineNumber = yylineno;
                                quadHandle.lineNumber = yylineno;
                                symbol* temp = symbTable.useSymbol(string($1));
                            }
    ;


for_loop_condition :
    expression            {$$ = $1;}
    ;

for_loop_increment :
    expression            {;}
    |
    assignment            {;}
    ;

while_loop
    : WHILE while_prefix  
    statement {
        quadHandle.jump_uncond_op($2->startLabel);  // Jump to start of loop
        quadHandle.writeToFile($2->endLabel + ":"); // Label for loop exit

        delete $2;  // cleanup
    }
    ;

while_prefix
    : while_label '(' expression ')' {
        quadHandle.jump_cond_op($3, $1->endLabel, false);
        $$ = $1;
    }
    ;

while_label
    : {
        LoopLabels* labels = new LoopLabels();
        labels->startLabel = quadHandle.generateLabel();
        labels->endLabel = quadHandle.generateLabel();

        quadHandle.writeToFile(labels->startLabel + ":");  // emit label BEFORE expr
        $$ = labels;
    }


switch_statement :
    SWITCH '(' expression ')' {
            string mainLabel = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(mainLabel);
            quadHandle.tempVars.push_back($3);
        }  
                             '{' switch_case '}' 
                             {printf("switch end\n");}
    ;

switch_case :
    CASE literal ':' {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* literal = quadHandle.tempVars[quadHandle.tempVars.size()-2];
        string startLabel = quadHandle.generateLabel();
        symbol* compare = quadHandle.math_op(operation::Minus, literal, $2);

        quadHandle.tempLabels.push_back(startLabel);
        quadHandle.jump_cond_op(compare, startLabel, false);
    } statement BREAK ';' {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        string mainLabel = quadHandle.tempLabels[quadHandle.tempLabels.size()-2];
        string endLabel = quadHandle.tempLabels.back();
        quadHandle.tempLabels.pop_back();
        quadHandle.jump_uncond_op(mainLabel);
        quadHandle.writeToFile((endLabel + ":").c_str());
    } switch_closing
    ;

switch_closing:
    CASE literal ':' {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* literal = quadHandle.tempVars[quadHandle.tempVars.size()-2];
        string startLabel = quadHandle.generateLabel();
        symbol* compare = quadHandle.math_op(operation::Minus, literal, $2);

        quadHandle.tempLabels.push_back(startLabel);
        quadHandle.jump_cond_op(compare, startLabel, false);
    } statement BREAK ';' {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        string mainLabel = quadHandle.tempLabels[quadHandle.tempLabels.size()-2];
        string endLabel = quadHandle.tempLabels.back();
        quadHandle.tempLabels.pop_back();
        quadHandle.jump_uncond_op(mainLabel);
        quadHandle.writeToFile((endLabel + ":").c_str());
    } switch_closing
    |
    DEFAULT ':' statement BREAK ';' {quadHandle.writeToFile((quadHandle.tempLabels.back() + ":").c_str()); quadHandle.tempLabels.pop_back();}
    |
    {quadHandle.writeToFile((quadHandle.tempLabels.back() + ":").c_str()); quadHandle.tempLabels.pop_back();}
    ;

expression :
    '(' expression ')' {$$ = $2;}
    |
    unary_expression {$$ = $1;}
    |
    function_call {$$ = $1;}
    |
    expression PLUS expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.math_op(operation::Plus, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression MINUS expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.math_op(operation::Minus, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression MUL expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.math_op(operation::Mul, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression DIV expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.math_op(operation::Div, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression MOD expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.math_op(operation::Mod, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression BIT_AND expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.bit_op(operation::Bit_and, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression BIT_OR expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.bit_op(operation::Bit_or, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression BIT_XOR expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.bit_op(operation::Bit_xor, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    MINUS expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.unary_op(operation::Neg, $2); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression EQ expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Eq, $1, $3);if (!vaiable) YYABORT;$$ = vaiable;}
    |
    expression NEQ expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Neq, $1, $3);if (!vaiable) YYABORT;$$ = vaiable;}
    |
    expression LT expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Lt, $1, $3);if (!vaiable) YYABORT;$$ = vaiable;}
    |
    expression GT expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Gt, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression LTE expression { quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Lte, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression GTE expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.rel_op(operation::Gte, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    NOT expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.unary_op(operation::Not, $2); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression AND expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.logic_op(operation::And, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    expression OR expression {quadHandle.lineNumber = yylineno; symbol* vaiable = quadHandle.logic_op(operation::Or, $1, $3); if(!vaiable) YYABORT; $$ = vaiable;}
    |
    literal {$$ = $1;}
    ;

unary_expression:
    ID INC      {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* vaiable = symbolTable::current->updateSymbol($1);
        if(vaiable==NULL){
            vaiable = new symbol($1, symbolType::ERROR, 1,1);
        }  
        $$ = quadHandle.unary_op(operation::Inc, vaiable);
     }
    |
    ID DEC       {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* vaiable = symbolTable::current->updateSymbol($1);
        if(vaiable==NULL){
            vaiable = new symbol($1, symbolType::ERROR, 1,1);
        }  
        $$ = quadHandle.unary_op(operation::Dec, vaiable);
     }
    ;


assignment :
    ID ASSIGN expression {     
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;       
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Assign, sym, $3);
    }
    |
    ID ADD_ASSIGN expression {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* var = symbolTable::current->useSymbol($1);
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Add_assign, sym, $3);
    }
    |
    ID SUB_ASSIGN expression {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* var = symbolTable::current->useSymbol($1);
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Sub_assign, sym, $3);
    }
    |
    ID MUL_ASSIGN expression {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* var = symbolTable::current->useSymbol($1);
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Mul_assign, sym, $3);
    }
    |
    ID DIV_ASSIGN expression {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* var = symbolTable::current->useSymbol($1);
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Div_assign, sym, $3);
    }
    |
    ID MOD_ASSIGN expression {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* var = symbolTable::current->useSymbol($1);
        symbol* sym = symbolTable::current->updateSymbol($1);
        if(sym == NULL){
            sym = new symbol($1, symbolType::ERROR, 1,1);
        }
        quadHandle.assign_op(operation::Mod_assign, sym, $3);
    }
    ;

literal :
    ID  {
        symbTable.lineNumber = yylineno;
        quadHandle.lineNumber = yylineno;
        symbol* temp = symbTable.useSymbol(string($1));
        if (temp == NULL) {
                temp = new symbol($1, symbolType::ERROR, 1,1);
        }
        $$ = temp;
    }   

    |
    INT_CONST                   { symbol* temp = new symbol($1, symbolType::INTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    LINT_CONST                  { symbol* temp = new symbol($1, symbolType::LINTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    LLINT_CONST                 { symbol* temp = new symbol($1, symbolType::LLINTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    FLOAT_CONST                 { symbol* temp = new symbol($1, symbolType::FLOATtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    CHAR_CONST                  { symbol* temp = new symbol($1, symbolType::INTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    DOUBLE_CONST               { symbol* temp = new symbol($1, symbolType::DOUBLEtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    STRING_CONST                { symbol* temp = new symbol($1, symbolType::STRINGtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    TRUE                        { symbol* temp = new symbol("true", symbolType::BOOLtype,1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    |
    FALSE                       { symbol* temp = new symbol("false", symbolType::BOOLtype,1,1); quadHandle.tempVars.push_back(temp); $$ = temp; }
    ;

type :
    INT         {$$ = symbolType::INTtype;}
    |
    LINT         {$$ = symbolType::LINTtype;}
    |
    LLINT         {$$ = symbolType::LLINTtype;}
    |
    FLOAT       {$$ = symbolType::FLOATtype;}
    |
    DOUBLE       {$$ = symbolType::DOUBLEtype;}
    |
    CHAR        {$$ = symbolType::CHARtype;}
    |
    STRING      {$$ = symbolType::STRINGtype;}
    |
    BOOL        {$$ = symbolType::BOOLtype;}
    ;
%%
/* Error handling */


void yyerror(const char *msg){
    errorManager.add(SYNTAX, yylineno, yytext, msg);
}

void yywarn(const char *msg){
    errorManager.add(WARNING, yylineno, "", msg);
}


int main(int argc, char *argv[]){

    printf("starting...\n");

    extern FILE* yyin;
    char* filename = argv[1];
    FILE* file = fopen(filename,"r");
    if(!file)
    {
        printf("File Error\n");
    }
    yyin = file;

    yyparse();
    symbTable.printSymbolTable(symbolTable::current);
    symbolTable::cleanUp();
    errorManager.reportAll();
    cout << "cleanup done" << endl;

    return 0;
}