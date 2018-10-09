%{
	#include<stdio.h>
    int x;
%}
%token INTEGER
%%
e:  e '+' t     {printf("+");}
    |t          {}
    ;
t:  t '*' f     {printf("*");}
    |f          {}
    ;
f:  INTEGER     {x = $1; printf("%d",x);}
    ;

%%
int main()
{
	yyparse();
    return 0;
}
void yyerror(char *s)
{
	// fprintf(stderr,"%s\n",s);
}
