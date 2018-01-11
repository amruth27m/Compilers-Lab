%{
#include<stdio.h>
void yyerror(const char* s);
%}

%token DIGIT
%token NEWLINE
%%

start	: pair NEWLINE	{printf("\n Compilation successfully completed\n");}
	;

pair	: num ',' num	{printf("\n pair(%d %d)",$1,$3);}
	;

num	: DIGIT		{$$ = $1;}
	;
%%

void yyerror(const char* s){
	printf("Error %s\n",s);
	return;
}

int main(){
	yyparse();
	return 1;
}
