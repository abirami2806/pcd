%{
	#include"y.tab.h"
	#include<stdio.h>
	#include<stdlib.h>
%}

number [0-9]+

%%
{number} {yylval.num = atoi(yytext);
		return DIGIT;}
"+" return PLUS;
"-" {return MINUS;}
"*" return MUL;
"/" return DIV;
%%

// int main()
// {
// 	int num = yylex();
// 	printf("Returned: %d", num);
// }

int yywrap()
{
	return 1;
}
