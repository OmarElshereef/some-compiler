
%{
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex(void);
    %}


%union {
    int i; // integer value
    char *s; // string value
    float f; // float value
    char c; // char value
}

/* C production rules */
%%
%%


/* subroutines */

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}


int main(){
    printf("Enter an expression:\n");
    yyparse();
    return 0;
}