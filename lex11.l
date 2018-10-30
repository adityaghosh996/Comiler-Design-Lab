%{
    #include "stdio.h"
    #include "stdlib.h"
    #include "y.tab.h"
%}
%%
[1-9]+[0-9]*                {return INT;}
[0-9]+[.][0-9]+             {return FLOAT;}
[+]                         {return *yytext;}
[-]                         {return *yytext;}
[*]                         {return *yytext;}
[=]                         {return *yytext;}
[\n]                        {return '\n';}
.                           {;}
%%

yywrap()
{}
