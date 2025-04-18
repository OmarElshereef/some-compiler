/* Definitions */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.tab.h"

%}


%%
[ \t\n]+         { /* Ignore whitespace */ }
[0-9]+          { yylval.i = atoi(yytext); return INTEGER; }
[()+-*/] { return yytext[0]; }
[ \t]+          { /* Ignore whitespace */ }
%%