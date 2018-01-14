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
printf("Answer %d", evaluate($1));
exit(1);
}
;

expr: PLUS ' ' expr ' ' expr{$$ = makeOperatorNode('+',$3,$5);}
	| MINUS ' ' expr ' ' expr {$$ = makeOperatorNode('-',$3,$5);}
	| MUL ' ' expr ' ' expr {$$ = makeOperatorNode('*',$3,$5);}
	| DIV ' ' expr ' ' expr {$$ = makeOperatorNode('/',$3,$5);}
	| NUM {$$ = $1;}
%%

void yyerror(char *s){
	printf("%s ", s);
}
int main(void){
	struct tnode* ans;
	yyparse();
	return 0;
}
