%{
    #include<stdio.h>
    #include<stdlib.h>
    int ha=0;
%}
%token d v colon comma space nl
%%
N:  S nl      {ha=1;return;}
    ;
S:  d space L colon
    ;
L:  v
    | v comma L
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