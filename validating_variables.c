%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>
%}

/*** YACC DECLARATION ***/

%token LETTER_
%token DIGIT

/*** RULES ***/

%%
	start : LETTER_ other '\n'
	{printf("The input string is a valid variable!");}
		;
	other : LETTER_ other
		| DIGIT other
		| {}
		;
%%

/*** AUXILIARY FUNCTIONS ***/

yyerror()
{
	printf("\nWrong Syntax!");
}

yylex()
{
	char ch;
	ch = getchar();
	if (isalpha(ch) || ch == '_')
		return LETTER_;
	else if (isdigit(ch))
		return DIGIT;
	else if (ch == ' ')
		yylex();
	else
		return ch;
}

int main()
{
	yyparse();
	return 1;
}
