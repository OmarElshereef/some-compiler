/* Definitions */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "./parser.tab.h"

%}

%option yylineno
/* defines */

ID	[a-zA-z][a-zA-z0-9_]*

%%
[ \t\n]+        { /* Ignore whitespace */ }
/* mathematical operators */
'+'             { return PLUS; }
'-'             { return MINUS; }
'*'             { return MUL; }
'/'             { return DIV; }
'%'             { return MOD; }
"++"            {return INC;}
"--"            {return DEC;}

/* assignment operators */
'='             { return ASSIGN; }
'+=             { return ADD_ASSIGN; }
'-='            { return SUB_ASSIGN; }
'*='            { return MUL_ASSIGN; }
'/='            { return DIV_ASSIGN; }
"%="            {return MOD_ASSIGN;}

/* relational operators */
'=='            { return EQ; }
'!='            { return NEQ; }
'<'             { return LT; }
'>'             { return GT; }
'<='            { return LTE; }
'>='            { return GTE; }

/* logical operators */
'!'             { return NOT; }
'&&'            { return AND; }
'||'            { return OR; }

/* bitwise operators */
"&"             {return BIT_AND;}
"|"             {return BIT_OR;}
"^"             {return BIT_XOR;}

/* semicolon and comma */
[;:,]       {return yytext[0];}

/* keywords */
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"do"            { return DO; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }

/* data types */
"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"double"        { return DOUBLE; }
"void"          { return VOID; }
"const"         { return CONST; }
"string"        {return STRING;}
"bool"          {return BOOL;}

/* boolean values */
"true"          {return TRUE;}
"false"         {return FALSE;}

/* identifiers */
{ID}        {yylval.sval = strdup(yytext); return ID;}


/* constants */
(0|[1-9][0-9]*)             {yylval.sval = strdup(yytext); return INT_CONST;}
(0|[1-9][0-9]*)\.[0-9]+     {yylval.sval = strdup(yytext); return FLOAT_CONST;}

/* strings */
(\"[^"]*\")                 {yylval.sval = strdup(yytext); return STRING_CONST;}

/* characters */
(\'[^\']\')                 {yylval.sval = strdup(yytext); return CHAR_CONST;}

/* comments */
(\/\/.*)                    ;
(\/\*(.|\n|\r)*\*\/)        ;

/* parentheses */
[(){}\[\]]                {return yytext[0];}

/* error */
.                           {printf("Error: Unrecognized token %s\n", yytext); exit(1);}
%%