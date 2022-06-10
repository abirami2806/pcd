%{
	#include<stdio.h>
	#include<stdlib.h>
	int yyerror(const char *s);

	// available in lex.yy.c
	extern FILE *yyin;
	extern int yylex();
%}

%union
{
	int num;
}

%type <num> expr
%token <num> DIGIT
%token PLUS MINUS MUL DIV
%token NEW

%left NEW
%left DIGIT
%left PLUS MINUS
%left MUL DIV

%%
start: expr { printf("\nAnswer = %d", $1); return 0;}
	;
expr: DIGIT { $$ = $1; }
	| expr PLUS expr { $$ = $1 + $3; printf("\nEvaluated: %d + %d = %d",$1, $3, $$); }
	| expr MINUS expr { $$ = $1 - $3; printf("\nEvaluated: %d - %d = %d",$1, $3, $$); }
	| expr MUL expr { $$ = $1 * $3; printf("\nEvaluated: %d * %d = %d",$1, $3, $$); }
	| expr DIV expr { $$ = $1 / $3; printf("\nEvaluated: %d / %d = %d",$1, $3, $$); }
	;
%%

int main()
{
	// FILE *fp = fopen("input.txt", "r");
	// yyin = fp;
	yyparse();
	return 1;
}

int yyerror(const char *s)
{
	printf("\nError! %s", s);
	return 0;
}
