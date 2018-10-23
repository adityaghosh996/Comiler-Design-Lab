%{
    #include "stdio.h"
    #include "stdlib.h"
    #include "y.tab.h"
%}
%%
int|float|char|double       {return d;}
[a-zA-Z_][a-zA-Z0-9]*       {return v;}
[a-zA-Z0-9_!@#$%^&*()_+]+   {;} 
;                           {return colon;}
,                           {return comma;}
[\n]                        {return nl;}
[ ]                         {return space;}
.                           {;}
%%

yywrap()
{}
