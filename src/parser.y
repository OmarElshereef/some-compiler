
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstring>
    #include "utils/symbolTable.hpp"
    #include "utils/quadHandler.hpp"
    #pragma once
    symbolTable symbTable = symbolTable();
    QuadHandler quadHandle = QuadHandler("output/quad.txt");
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

    int inFunction = 0;
    %}

%union {
    char *sval;
    symbol* symboll;
    symbolType symbolTypeType;
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
%type <symboll> math_or_value
%type <symboll> expression 
%type <symboll> condition 
%type <symboll> unary_expression
%type <symboll> literal
%type <symboll> assignment
//%type <symboll> initialization
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
        ;
                
matched_statement :
        IF '(' condition ')' {
            string tempLabel = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(tempLabel);
            quadHandle.jump_cond_op($3, tempLabel.c_str(), false);
        } matched_statement ELSE {
            string ifLabel = quadHandle.tempLabels.back();
            quadHandle.tempLabels.pop_back();
            string label = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(label);
            quadHandle.writeToFile("jmp " + label);
            quadHandle.writeToFile(ifLabel + ":");
        } 
        matched_statement {string label = quadHandle.tempLabels.back(); quadHandle.tempLabels.pop_back(); quadHandle.writeToFile(label + ":");} 
        | other_stmt {;}
        ;

unmatched_statement :
        IF '(' condition ')' {
            string tempLabel = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(tempLabel);
            quadHandle.jump_cond_op($3, tempLabel.c_str(), false);
        } statement %prec LOWER_THAN_ELSE  {string label = quadHandle.tempLabels.back(); quadHandle.tempLabels.pop_back(); quadHandle.writeToFile(label + ":");} 
        |
        IF '(' condition ')' {
            string tempLabel = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(tempLabel);
            quadHandle.jump_cond_op($3, tempLabel.c_str(), false);
        } matched_statement ELSE {
            string ifLabel = quadHandle.tempLabels.back();
            quadHandle.tempLabels.pop_back();
            string label = quadHandle.generateLabel();
            quadHandle.tempLabels.push_back(label);
            quadHandle.writeToFile("jmp " + label);
            quadHandle.writeToFile(ifLabel + ":");
        } 
        unmatched_statement {string label = quadHandle.tempLabels.back(); quadHandle.tempLabels.pop_back(); quadHandle.writeToFile(label + ":");}
        ;

other_stmt :
        declaration ';'             { printf("Declaration\n"); }
        | 
        initialization ';'        { printf("Initialization\n"); }
        | 
        assignment ';'            { printf("Assignment\n"); }
        | 
        unary_expression ';'      { printf("Unary Expression\n"); }
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
        function_call ';'         { printf("Function_call\n"); }
        | 
        ID ';'                    { printf("ID\n"); }
        | 
        '{' {symbTable.changeScope(1);} program '}' {symbTable.changeScope(0);}    { printf("Scope end\n"); }
        ;


declaration
    : type ID                                  {
            symbol* sym = symbolTable::current->addSymbol($2,$1,false, false);
            if (!sym) printf("initialization error\n");
        }
    ;


initialization
    : type ID ASSIGN expression {
            symbol* sym = symbolTable::current->addSymbol($2,$1,false, true);
            if (!sym) YYABORT;
            quadHandle.assign_op(operation::Assign, sym, $4);
        }
    | CONST type ID ASSIGN expression    {
            symbol* sym = symbolTable::current->addSymbol($3,$2,true, true);
            if (!sym) YYABORT;
            quadHandle.assign_op(operation::Assign, sym, $5);
    }
    ;


function_definition :
    function_declaration_prototype {if(inFunction) yyerror("You cannot declare a function inside a function."); inFunction = 1;} '{' program return_statement ';' '}' { 
        inFunction = 0; 
        symbTable.changeScope(0); 
        functionParameters[$<sval>1] = currentFunctionParameters;
        currentFunctionParameters.clear();
        currFunctionReturn = symbolType::UNKNOWN;
        }
    ;

function_declaration_prototype : //gives  warning: type clash on default action: error
    VOID ID {symbTable.setUsed(symbTable.addOrUpdateSymbol(string($2),symbolType::VOIDtype,NULL,0,1)); symbTable.changeScope(1); currFunctionReturn = symbolType::VOIDtype;} '(' function_parameters_optional ')' {quadHandle.declare_func_op(symbTable.findSymbol(string($2)), currentFunctionParameters); $$=$2;}  // isInitialized = 1 because it is a function
    |
    type ID {symbTable.setUsed(symbTable.addOrUpdateSymbol(string($2),$1,NULL,0,1)); symbTable.changeScope(1); currFunctionReturn = $1;} '(' function_parameters_optional ')' {quadHandle.declare_func_op(symbTable.findSymbol(string($2)), currentFunctionParameters); $$=$2;}  // isInitialized = 1 because it is a function
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
    type ID             {symbol* s = symbTable.addOrUpdateSymbol(string($2),$1,NULL,0,1); currentFunctionParameters.push_back(s);} // isInitialized = 1 because it is a function
    ;

return_statement :
    RETURN expression   {quadHandle.return_op($2, currFunctionReturn);}
    |
    RETURN              {quadHandle.return_op(NULL, currFunctionReturn);}
    ;

function_call : 
    ID '(' function_arguments_optional ')' 
    {
        symbol* temp = symbTable.findSymbol(string($1));
        if(!functionParameters.count(string(temp->name))) yyerror("There is not a function with this name.");
        vector<symbol*> params = functionParameters[string(temp->name)];
        if(params.size() != functionCallParameters.size()) yyerror("Number of parameters does not match.");
        for(int i = 0; i < params.size(); i++)
        {
            if(!quadHandle.tryCast(functionCallParameters[i],params[i]->type)) yyerror("Parameter types do not match.");
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
           '(' condition ')'      {quadHandle.jump_cond_op($9, $<sval>2, true);}
        ;

for_loop :
        FOR 
        '(' for_loop_initialization ';' 
        condition ';' 
        for_loop_increment ')' 
        statement 
        ;

for_loop_initialization :
    INT ID ASSIGN INT_CONST {;}
    |
    ID ASSIGN INT_CONST     {;}
    ;


for_loop_increment :
    expression            {;}
    |
    assignment            {;}
    ;

while_loop :
    WHILE 
    '(' expression ')' 
    statement    {;}
    ;

switch_statement :
    SWITCH '(' expression ')' {symbTable.changeScope(1);} 
                             '{' switch_case '}' 
                             {symbTable.changeScope(0);}
    ;

switch_case :
    CASE literal ':' statement;
    |
    DEFAULT ':' statement;
    ;

expression :
    math_or_value {$$ = $1;}
    |
    '(' expression ')' {$$ = $2;}
    |
    unary_expression {$$ = $1;}
    |
    function_call {$$ = $1;}
    ;

condition :
    expression {$$ = $1;}
    |
    expression EQ expression {
        symbol* rizz = quadHandle.rel_op(operation::Eq, $1, $3);
        if (!rizz) YYABORT;
        $$ = rizz;}
    |
    expression NEQ expression {
        symbol* rizz = quadHandle.rel_op(operation::Neq, $1, $3);
        if (!rizz) YYABORT;
        $$ = rizz;}
    |
    expression LT expression {
        symbol* rizz = quadHandle.rel_op(operation::Lt, $1, $3);
        if (!rizz) YYABORT;
        $$ = rizz;}
    |
    expression GT expression {symbol* rizz = quadHandle.rel_op(operation::Gt, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    expression LTE expression {symbol* rizz = quadHandle.rel_op(operation::Lte, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    expression GTE expression {symbol* rizz = quadHandle.rel_op(operation::Gte, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    NOT condition {symbol* rizz = quadHandle.unary_op(operation::Not, $2); if(!rizz) YYABORT; $$ = rizz;}
    |
    condition AND condition {symbol* rizz = quadHandle.logic_op(operation::Eq, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    condition OR condition {symbol* rizz = quadHandle.logic_op(operation::Eq, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    ;


math_or_value : 
    math_or_value PLUS math_or_value {symbol* rizz = quadHandle.math_op(operation::Plus, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value MINUS math_or_value {symbol* rizz = quadHandle.math_op(operation::Minus, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value MUL math_or_value {symbol* rizz = quadHandle.math_op(operation::Mul, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value DIV math_or_value {symbol* rizz = quadHandle.math_op(operation::Div, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value MOD math_or_value {symbol* rizz = quadHandle.math_op(operation::Mod, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value BIT_AND math_or_value {symbol* rizz = quadHandle.bit_op(operation::Bit_and, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value BIT_OR math_or_value {symbol* rizz = quadHandle.bit_op(operation::Bit_or, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    math_or_value BIT_XOR math_or_value {symbol* rizz = quadHandle.bit_op(operation::Bit_xor, $1, $3); if(!rizz) YYABORT; $$ = rizz;}
    |
    MINUS math_or_value {symbol* rizz = quadHandle.unary_op(operation::Neg, $2); if(!rizz) YYABORT; $$ = rizz;}
    |
    literal {$$ = $1;}
    ;

unary_expression:
    ID INC      {symbol* rizz = symbolTable::current->findSymbol($1); if(!rizz) YYABORT; $$ = quadHandle.unary_op(operation::Inc, rizz);}
    |
    ID DEC      {symbol* rizz = symbolTable::current->findSymbol($1); if(!rizz) YYABORT; $$ = quadHandle.unary_op(operation::Dec, rizz);}
    ;


assignment :
    ID ASSIGN expression {            
            symbol* sym = symbolTable::current->findSymbolDeclared($1);
            if (!sym) YYABORT;
            quadHandle.assign_op(operation::Assign, sym, $3);}
    ;

literal :
    ID                          {$$ = symbTable.setUsed(symbTable.findSymbol(string($1)));}
    |
    INT_CONST                   {symbol* temp = new symbol($1, symbolType::INTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
    |
    FLOAT_CONST                 {symbol* temp = new symbol($1, symbolType::FLOATtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
    |
    CHAR_CONST                  {symbol* temp = new symbol($1, symbolType::INTtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
    |
    STRING_CONST                {symbol* temp = new symbol($1, symbolType::STRINGtype, 1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
    |
    TRUE                        {symbol* temp = new symbol("true", symbolType::BOOLtype,1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
    |
    FALSE                       {symbol* temp = new symbol("false", symbolType::BOOLtype,1,1); quadHandle.tempVars.push_back(temp); $$ = temp;}
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
    extern int yylineno;
    fprintf(stderr, "Error: %s at line %d\n", msg, yylineno);
    fprintf(stdout, "\nError: %s at line %d\n", msg, yylineno);
    exit(1);
}

void yywarn(const char *msg){
    fprintf(stderr, "Warning: %s\n", msg);
    fprintf(stdout, "\nWarning: %s\n", msg);
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
    cout << "cleanup done" << endl;

    return 0;
}