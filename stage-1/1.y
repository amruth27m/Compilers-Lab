%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE tnode*
#include "exprtree.h"
#include "exprtree.c"
struct tnode* ans;
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

expr: expr PLUS expr{ ans = makeOperatorNode('+' ,$1,$3);}
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
	print_prefix(ans);
	print_postfix(ans);
	return 0;
}
