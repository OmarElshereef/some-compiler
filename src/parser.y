
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstring>
    #include "utils/symbolTable.hpp"

    symbolTable symbTable = symbolTable();
    int symbolTable::numScopes = 0;
    vector<vector<symbolTable*>> symbolTable::symbolTableAdj = vector<vector<symbolTable*>>(1,vector<symbolTable*>());
    symbolTable* symbolTable::current = &symbTable;

    void yyerror(const char *s);
    int yylex(void);
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
%token CONST INT FLOAT CHAR STRING BOOL VOID

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
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
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
%left FUNC

/* Other tokens */
%token <sval> ID
%token <sval> INT_CONST
%token <sval> FLOAT_CONST
%token <sval> STRING_CONST
%token <sval> CHAR_CONST

%type <sval> function_declaration_prototype
%type <sval> one_level_if_statement
%type <symboll> for_loop_condition
%type <symboll> evaluate_expression 
%type <symboll> math_or_value  
%type <symboll> expression 
%type <symboll> condition 
%type <symboll> unary_expression
%type <symboll> literal
%type <symboll> assignment
%type <symboll> initialization
%type <symboll> function_call
%type <symbolTypeType> type
%type <operationName> assign


/* Grammar */
%%

program :
        program statement       {;}
        |                       {;}
        ;

statement :
        declaration ';'           { printf("Declaration\n"); }
        | 
        initialization ';'        { printf("Initialization\n"); }
        | 
        assignment ';'            { printf("Assignment\n"); }
        | 
        unary_expression ';'      { printf("Unary Expression\n"); }
        | 
        { printf("If statement start\n"); }   if_statement              { printf("If statement end\n"); }
        | 
        { printf("Switch case start\n"); }    switch_statement          { printf("Switch case end\n"); }
        | 
        { printf("Do while loop start\n"); }  do_loop ';'               { printf("Do while loop end\n"); }
        | 
        { printf("While loop start\n"); }     while_loop                { printf("While loop end\n"); }
        | 
        { printf("For loop start\n"); }       for_loop                  { printf("For loop end\n"); }
        | 
        function_definition       { printf("Function_definition\n"); }
        | 
        function_call ';'         { printf("Function_call\n"); }
        |
        { printf("Scope start\n"); }          '{' {symbTable.changeScope(1);} program '}' {symbTable.changeScope(0);}    { printf("Scope end\n"); }
        ;

do_loop :
        DO {symbTable.changeScope(1);} 
           '{' program '}' 
           WHILE 
           {symbTable.changeScope(0);} 
           '(' expression ')'      {;}
        ;

for_loop :
        FOR {symbTable.changeScope(1);} 
            '(' for_loop_initialization ';' 
            for_loop_condition ';' 
            for_loop_increment ')' 
            '{' program '}' 
            {symbTable.changeScope(0);}
        ;

for_loop_initialization :
    INT ID ASSIGN INT_CONST {
                                symbTable.addOrUpdateSymbol(string($2), symbolType::INTtype, new symbol(string($4), symbolType::INTtype, 1,1), 0, 1);
                            }
    |
    ID ASSIGN INT_CONST     {
                                symbTable.addOrUpdateSymbol(string($1), symbolType::UNKNOWN, new symbol(string($3), symbolType::INTtype, 1,1), 0, 1);
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

while_loop :
    WHILE {;}  
    '(' expression ')' {symbTable.changeScope(1);} 
    '{' program '}'    {symbTable.changeScope(0);}
    ;


if_statement :
    one_level_if_statement {;}
    |
    one_level_if_statement ELSE {symbTable.changeScope(1);} '{' program '}' {symbTable.changeScope(0);}
    ;

one_level_if_statement :
    IF '(' expression ')' {symbTable.changeScope(1);} 
                          '{' program '}'    
                          {symbTable.changeScope(0);}
    ;


literal :
    ID                          {$$ = symbTable.setUsed(symbTable.findSymbol(string($1)));}
    |
    INT_CONST                   {$$ = new symbol($1, symbolType::INTtype, 1,1);}
    |
    FLOAT_CONST                 {$$ = new symbol($1, symbolType::FLOATtype, 1,1);}
    |
    CHAR_CONST                  {$$ = new symbol($1, symbolType::INTtype, 1,1);}
    |
    STRING_CONST                {$$ = new symbol($1, symbolType::STRINGtype, 1,1);}
    |
    TRUE                        {$$ = new symbol("true", symbolType::BOOLtype,1,1);}
    |
    FALSE                       {$$ = new symbol("false", symbolType::BOOLtype,1,1);}
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