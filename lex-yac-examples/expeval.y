%{
#include<stdio.h>
int yyerror();
%}

%token DIGIT
%token NEWLINE

%left '+' '-'
%left '*'


%%

start	: expr NEWLINE	{	printf("\n Result is %d ",$1);	}
	;
expr 	: expr '+' expr	{	$$ = $1 + $3; 	}
	;
expr	: expr '-' expr	{ 	$$ = $1 - $3;	}
	;
expr	: expr '*' expr	{	$$ = $1 * $3;	}
	;
expr	: '(' expr ')'	{	$$ = $2;	}
	;
expr 	: DIGIT		{	$$ = $1; printf("exp val = %d", $$);	}
	;
%%

int yyerror(){
	return 0;
}

int main(){
	yyparse();
	return 1;
}
