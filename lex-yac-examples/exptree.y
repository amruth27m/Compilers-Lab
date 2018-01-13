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
$$ = $2;
printf("Answer %d\n",evaluate($1));
exit(1);
}
;

expr: expr PLUS expr{ $$ = makeOperatorNode('+' ,$1,$3);}
	| expr MINUS expr { $$ = makeOperatorNode('-',$1,$3);}
	| expr MUL expr { $$ = makeOperatorNode('*',$1,$3);}
	| expr DIV expr { $$ = makeOperatorNode('/',$1,$3);}
	| '(' expr ')' { $$ = $2; }
	| NUM { $$ = $1; }
%%

void yyerror(char *s){
	printf("%s ", s);
}
int main(void){
	yyparse();
	return 0;
}
