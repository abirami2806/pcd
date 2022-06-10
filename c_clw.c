%{
#include<stdio.h>
int n_chars=0, n_words = 0, n_lines = 0;
%}

words [^ \t\n]+

%%

{words} {n_words++; n_chars+=yyleng;} 
[\n] {n_words++; n_lines++;}
. {n_chars++;}

%%

int main()
{
	yyin = fopen("input_file1.txt", "r");
	printf("Counting the number of characters, words and lines in a file");
	printf("\n***NOTE:\n\tCharacters include all characters except newline");
	printf("\n\tWords include anything bounded by whitespace on either side of it");
	printf("\n\tLines indicate the number of newline characters***");
	yylex();
	printf("\n");
	printf("\nNumber of characters = %d", n_chars);
	printf("\nNumber of words = %d", n_words);
	printf("\nNumber of lines = %d", n_lines);
	printf("\n");
	return 1;
}

int yywrap()
{

	return 1;
}
