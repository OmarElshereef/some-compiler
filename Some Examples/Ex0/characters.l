%{
    int nchar;
    int nword;
    int nline;
%}

%%

\n      { nline++; nchar++; }

[^ \t\n]+      { nword++; nchar+=yyleng; }

.           { nchar++; }

%%

int main(void) {
  yylex();
  printf("%d\t%d\t%d\t%d\n", nchar, nword, nline);
  return 0;
}

int yywrap(void) {
    return 1;
}
