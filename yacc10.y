%{
	#include<stdio.h>
%}
%token INTEGER
%%
N:  E '\n'      {printf("%d \n",$1);}
    ;
E: INTEGER      {$$ = $1;}
   | E E '+'    {$$ = $1 + $2;}
   | E E '-'    {$$ = $1 - $2;}
   | E E '*'    {$$ = $1 * $2;}
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
