%{
    #include<stdio.h>
    #include<stdlib.h>
%}
%token Z O
%%
N:  L       {printf("\n%d",$$);}
    ;
L:  L B     {$$=$1*2+$2;}
    | B     {$$=$1;}
    ;
B:  Z    {$$=$1;}
    |O    {$$=$1;}
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