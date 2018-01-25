%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE tnode*
#include "exprtree.h"
#include "exprtree.c"
extern int ylineno;
%}
%token BEG END READ WRITE ID CONSTANT
%left PLUS MIN
%left MUL DIV
%%

program: BEG '\n' slist END '\n'{    
printf("Evaluation successfully completed");
$$ = $3;
evalTree($$,stdout);
exit(1);
}
	| BEG END  {
printf("Evaluation successfully completed");
exit(1);
}
;
slist: 	stmt ';' '\n' slist { $$ = createTreeNode(0,3,'n',$1,$4);}
	| stmt ';' '\n' { $$ = $1;}
	;
stmt: inputstmt {$$ = $1;} 
	| outputstmt {$$ = $1;} 
	| assignstmt {$$ = $1;}
	;
inputstmt: READ ' ' '(' ID ')' {$$ = createTreeNode(0,2,'r',$4,NULL);}
	;
outputstmt: WRITE ' ''(' E ')' {$$ = createTreeNode(0,2,'w',$4,NULL);}
	;
assignstmt: ID ' ' '='  ' ' E  {$$ = createTreeNode(0,2,'=',$1,$5);}	
	;
E: 	  f ' ' PLUS ' ' E  {$$ = createTreeNode(0,2,'+',$1,$5);}
	| f ' ' MIN ' ' E  {$$ = createTreeNode(0,2,'-',$1,$5);}
	| f ' ' DIV ' ' E  {$$ = createTreeNode(0,2,'/',$1,$5);}
	| f ' ' MUL ' ' E  {$$ = createTreeNode(0,2,'*',$1,$5);}
	| f { $$ = $1;}
	| '(' E ')'	{ $$ = $2;}
	;
f:	ID {$$ = $1;}
	| CONSTANT {$$ = $1;}
	;
%%

void yyerror(char *s){
	printf("%s %d", s,ylineno);
}
int main(void){
	extern FILE* yyin;
	yyin = fopen("ip","r");
	yyparse();
	return 0;
}
