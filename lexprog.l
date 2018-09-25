%{
	#include"y.tab.h"
	int yylval;
%}

%%
[0-9]+ {
	yylval = atoi(yytext);
	return INTEGER;
}
[+*] {return *yytext;}
%%

int yywrap(void)
{
}
