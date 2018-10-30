%{
#include<stdio.h>
%}
%token INT FLOAT
%%
P:F '\n' 	{ printf("Validated");}
 |
 ;
F: E '=' E     {if($1==$3){$$=$1;}else{yyerror();return;}}
 |
 ;
E: INT	       { $$ = INT;}
 | FLOAT         { $$ = FLOAT;}
 | E '+' E	   { if($1==$3){$$=$1;}else{yyerror();return;}}
 | E '-' E	   { if($1==$3){$$=$1;}else{yyerror();return;}}
 | E '*' E	   { if($1==$3){$$=$1;}else{yyerror();return;}}
 ;
%%
int main()
{
yyparse();
return 0;
}
yyerror()
{
printf("Error spotted\n");
_Exit ;
}
