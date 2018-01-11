%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
int yywrap();
%}

digit [0-9]

%%

[0-9]+	 { 
			yylval = atoi(yytext);
			return DIGIT;
		}
[\n] 		{
			return NEWLINE;
		}
","		{
			return *yytext;
		}

%%
int yywrap(){
	return 1;
}

