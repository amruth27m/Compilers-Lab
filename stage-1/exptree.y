%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE tnode*
#include "exprtree.h"
#include "exprtree.c"
%}
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV
%%

program: expr END{
printf("successfully parsed");
exit(1);
}
;

expr: PLUS ' ' expr ' ' expr{}
	| MINUS ' ' expr ' ' expr {}
	| MUL ' ' expr ' ' expr {}
	| DIV ' ' expr ' ' expr {}
	| NUM {}
%%

void yyerror(char *s){
	printf("%s ", s);
}
int main(void){
	struct tnode* ans;
	yyparse();
	print_tree(stdout,ans,2);
	return 0;
}
