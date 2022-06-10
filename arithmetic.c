%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<ctype.h>
%}

/*** YACC DECLARATION SECTION ***/

%token DIGIT
%left '+'
%left '-'
%left '*'
%left '/'

/*** RULES SECTION ***/

%%
start: expr'\n' {printf("\nThis is valid!");}
	;
expr : expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	|number
	;
number : DIGIT number | {}
	;
/*** binaryOp : '+' ***/
	;
%%

/*** AUXILIARY FUNCTIONS SECTION ***/

yyerror(char const *s)
{
	printf("\nError occured!");
}

yylex()
{
	char ch;

	// clear the input buffer
	// while ((ch=getchar())!='\n' && c!=EOF);

	// get and process input
	ch = getchar();
	if (isdigit(ch))
		return DIGIT;
	else if (ch == ' ')  // ignore white space
		yylex();
	else
		return ch;
}

main()
{
	yyparse();
	return 1;
}
