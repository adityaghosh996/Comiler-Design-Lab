%{
    #include "stdlib.h"
    #include "y.tab.h"
    int yylval;
%}
%%
[0-9]+      {yylval = atoi(yytext);return INTEGER;}
[-+*\n]     {return *yytext;}
[\t]        {;/*skip whitespace*/}
[ ]         {;}
.           {printf("%s = invalid character\n",yytext);}
%%

yywrap()
{}
