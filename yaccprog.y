%{
	#include<stdio.h>
%}
%token INTEGER
%%
S : E	{printf("The answer is = %d\n",$1);}
E : INTEGER { $$ = $1;}
  | E '+' E	{$$ = $1 + $3;}
  | E '*' E	{$$ = $1 * $3;}
  ;
%%
main()
{
	yyparse();
}
yyerror()
{
	printf("Error spotted");
}
