
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
%token <i> INTEGER
%type <i> S E T F

/* C production rules */

%%

S:E{ printf("Result: %d\n", $1);}
;

E:E '+' T {$$ = $1 + $3;}
| E '-' T {$$ = $1 - $3;}
| T {$$ = $1;}
;

T:T '*' F {$$ = $1 * $3;}
| T '/' F {if($3 == 0){ yyerror("division by zero");}$$ = $1 / $3;}
| F {$$ = $1;}
;

F:'(' E ')' {$$ = $2;}
| '-' F {$$ = -$2;}
| INTEGER {$$ = $1;}
;
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