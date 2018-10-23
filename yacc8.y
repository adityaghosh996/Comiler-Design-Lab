%{
    #include<stdio.h>
    #include<stdlib.h>
    int ha=0;
%}
%token A B C nl
%%
N:  S nl      {ha=1;return;}
    ;
S:  A S B     
    | B S A   
    | C     
    ;
%%
int main()
{
    yyparse();
    if(ha==1)
        printf("Valid String\n");
    else
        printf("Invalid String\n");
    return 0;
}
void yyerror(char *s)
{
	// fprintf(stderr,"%s\n",s);
}