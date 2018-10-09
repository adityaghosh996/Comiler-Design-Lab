%{
    #include "stdio.h"
    #include "stdlib.h"
    #include "y.tab.h"
    int yylval;
%}
%%
0       {yylval=0;return Z;}
1       {yylval=1;return O;}
[\t]    {;/*skip whitespace*/}
[\n]    {return 0;}
.       {return yytext[0];}
%%

yywrap()
{}
