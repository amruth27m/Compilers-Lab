%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
#define YYSTYPE tnode*

struct tnode* makeLeafNode(int num);
int number;
%}
%%

[0-9]+ { number = atoi(yytext); yylval = makeLeafNode(number); return NUM; }
"+" {return PLUS; }
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV; }
[\t] {}
[()] {return *yytext;}
[\n] {return END; }
. {yyerror("Unknown character\n"); exit(1);}
%%
int yywrap(void){
	return 1;
}

