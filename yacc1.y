%{
	#include<stdio.h>
%}
%token INTEGER
%%
p:p e '\n'      {printf("%d \n",$2);}
    |
    ;
e: INTEGER      {$$ = $1;}
   | e '+' e    {$$ = $1 + $3;}
   | e '-' e    {$$ = $1 - $3;}
   | e '*' e    {$$ = $1 * $3;}
   ;
%%
int main()
{
	yyparse();
    return 0;
}
void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
}
