%{
#include<stdio.h>
int linecount = 0;
int wordcount = 0;
int charactercount = 0;
%}

whitespace [ \t\r]+
endofline [\n]
allchar [^\n\t]

%option noyywrap
%%

({endofline}) {linecount++; wordcount++; charactercount++;}
({whitespace}) {wordcount++; charactercount++;}
({allchar}) {charactercount++; }
%%
int main(){
	int lc = yylex();
	printf("\nNumber of lines in the input %d",linecount+1);
	printf("\nNumber of words in the input %d",wordcount+1);
	printf("\nNumber of characters in the input %d",charactercount+1);

}
