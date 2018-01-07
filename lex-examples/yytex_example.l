%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
	
oddnumber [0-9]*[1|3|5|7|9]
evennumber [0-9]*[2|4|6}8}0]
 
%%
 
{oddnumber} {printf("Found odd : %d\n",atoi(yytext));}
{evennumber} {printf("Found even : %d\n",atoi(yytext));}
 
%%
 
int main()
{
	yylex();
	return 1;
}
