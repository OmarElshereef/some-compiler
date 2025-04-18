/* Definitions */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

%}


%%
[ \t\n]+        { /* Ignore whitespace */ }
'+'             { return PLUS; }
'-'             { return MINUS; }
'*'             { return MULTIPLY; }
'/'             { return DIVIDE; }
'%'             { return MOD; }
'&'             { return AND; }
'|'             { return OR; }
'^'             { return XOR; }
'='             { return ASSIGN; }
'+=             { return PLUSASSIGN; }
'-='            { return MINUSASSIGN; }
'*='            { return MULTIPLYASSIGN; }
'/='            { return DIVIDEASSIGN; }
'=='            { return ISEQUAL; }
'!='            { return NOTEQUAL; }
'<'             { return LESS; }
'>'             { return GREATER; }
'<='            { return LESSEQUAL; }
'>='            { return GREATEREQUAL; }
'!'             { return LOGICNOT; }
'&&'            { return LOGICAND; }
'||'            { return LOGICOR; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
';'             { return SEMICOLON; }
':'             { return COLON; }
','             { return COMMA; }          
"if"            { return IF; }
"else"          { return ELSE; }
"else if"       { return ELSEIF; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"do"            { return DO; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"double"        { return DOUBLE; }
"void"          { return VOID; }
"const"         { return CONST; }
[0-9]+          { yylval.i = atoi(yytext); return INTEGER; }
[0-9]+"."([0-9]+)? { yylval.f = atof(yytext); return FLOATING; }
\"([^\\\"]|\\.)*\"      { yylval.s = strdup(yytext); return STRING; }
\'([^\\']|\\.)\'        { yylval.c = yytext[1]; return CHARACTER; }
[a-zA-Z_][a-zA-Z0-9_]* {
                    if (strcmp(yytext, "true") == 0) {
                        return TRUE;
                    } else if (strcmp(yytext, "false") == 0) {
                        return FALSE;
                    } else {
                        yylval.s = strdup(yytext);
                        return IDENTIFIER;
                    }
                }
%%