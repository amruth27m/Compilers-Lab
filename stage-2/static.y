%{
#include<stdio.h>
#include<stdlib.h>
#define YYSTYPE tnode*
#include "exprtree.h"
#include "exprtree.c"
extern int ylineno;
%}
%token BEG END READ WRITE ID CONSTANT IF THEN ELSE ENDIF WHILE ENDWHILE DO CONTINUE BREAK DECL ENDDECL INT STR
%left PLUS MIN
%left MUL DIV
%nonassoc LT LTE GT GTE EQ NEQ
%%

program:  GDeclBlock MainBlock {$$ = $2;
		printf("successfully evaluated the source code\n");
		FILE *fp = fopen("out","w");
		codeGen($$,fp);
		printSymbolTable();
		exit(1);
	}
	| MainBlock {
		$$ = $1;
		printf("successfully evaluated the source code\n");
		FILE *fp = fopen("out","w");
		codeGen($$,fp);
		printSymbolTable();
		exit(1);
	}
	;

GDeclBlock: DECL '\n' Declist ENDDECL '\n'{ printf("successfully constructed symbol table\n");}
	| DECL'\n' ENDDECL '\n'{ printf("successfully constructed symbol table\n"); }
	;

Declist: Decl ';' '\n' Declist {$$ = $1;} 
	| Decl ';' '\n' {$$ = $1;}

Decl: Type ' ' Varlist  {createDeclarations($1,$3);}

Type: 	INT {$$ = $1;}
	| STR {$$ = $1;}

Varlist: ID ',' Varlist {$$ = linkVarNode($1,$3);}
	| ID '[' CONSTANT ']' ',' Varlist {$$ = linkArrayNode($1,$3->val,$6);}
	| ID '[' CONSTANT ']' '[' CONSTANT ']' ',' Varlist {$$ = linkMatrixNode($1,$3->val,$6->val,$9);}
	| ID '[' CONSTANT ']' {$$ = createArrayNode($1,$3->val);}
	| ID '[' CONSTANT ']' '[' CONSTANT ']' {$$ = createMatrixNode($1,$3->val,$6->val);}
	| ID {$$ = createVarNode($1);}




MainBlock: BEG '\n' slist END '\n' {
	$$ = $3;
	}
	| BEG '\n' END '\n' {
	$$ = NULL;	
	}
	
slist: 	stmt ';' '\n' slist { $$ = createTreeNode(0,3,NULL,NULL,$1,$4);}
	| stmt ';' '\n' { $$ = $1;}
	;


stmt: inputstmt {$$ = $1;} 
	| outputstmt {$$ = $1;} 
	| assignstmt {$$ = $1;}
	| ifstmt {$$ = $1;}
	| whilestmt {$$ = $1;}
	| breakstmt {$$ = $1;}
	| continuestmt {$$ = $1;}
	;
inputstmt: READ  '(' ID ')' {$$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' CONSTANT ']' ')' {$3 = appendConstantVal($3,$5->val); $$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' ID ']' ')' {$3 = appendVariableVal($3,$5->varname); $$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' CONSTANT ']''[' CONSTANT ']' ')' {$3 = appendDoubleConst($3,$5->val,$8->val); $$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' ID ']' '[' ID ']' ')' {$3 = appendDoubleVar($3, $5->varname,$8->varname); $$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' CONSTANT ']' '[' ID ']' ')' {$3 = appendConstVar($3, $5->val,$8->varname);$$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	| READ '(' ID '[' ID ']' '[' CONSTANT ']' ')' {$3 = appendVarConst($3,$5->varname,$8->val);$$ = createTreeNode(0,5,NULL,'r',$3,NULL);}
	;
outputstmt: WRITE '(' E ')' {$$ = createTreeNode(0,5,NULL,'w',$3,NULL);}
	;
assignstmt: ID  '='   E  {$$ = createTreeNode(0,2,NULL,'=',$1,$3);}	
	| ID '[' CONSTANT ']' '=' E {$1 = appendConstantVal($1,$3->val); $$ = createTreeNode(0,2,NULL,'=',$1,$6);}
	| ID '[' ID ']' '=' E {$1 = appendVariableVal($1,$3->varname); $$ = createTreeNode(0,2,NULL,'=',$1,$6);}
	| ID '[' CONSTANT ']' '[' CONSTANT ']' '=' E {$1 = appendDoubleConst($1,$3->val,$6->val);  $$ = createTreeNode(0,2,NULL,'=',$1,$9);}
	| ID '[' ID ']' '[' ID ']' '=' E {$1 = appendDoubleVar($1,$3->varname,$6->varname); $$ = createTreeNode(0,2,NULL,'=',$1,$9);}
	| ID '[' ID ']' '[' CONSTANT ']' '=' E {$1 = appendVarConst($1,$3->varname,$6->val);  $$ = createTreeNode(0,2,NULL,'=',$1,$9);}
	| ID '[' CONSTANT ']' '[' ID ']' '=' E {$1 = appendConstVar($1,$3->val,$6->varname); $$ = createTreeNode(0,2,NULL,'=',$1,$9);}
	;

breakstmt: BREAK {$$ = createBreakNode(BREAK_STATEMENT);}
continuestmt: CONTINUE {$$ = createBreakNode(CONTINUE_STATEMENT);}

ifstmt:   IF '(' E ')' THEN '\n' slist ENDIF {$$ = createConditionalNode(CIF_ELSE,$3,$7,NULL);}
	| IF '(' E ')' THEN '\n' slist ELSE '\n' slist ENDIF {$$ = createConditionalNode(CIF,$3,$7,$10);}
	;
whilestmt: WHILE '(' E ')'  DO '\n' slist  ENDWHILE {$$ = createConditionalNode(CWHILE,$3,NULL,$7); }

E: 	  f  PLUS  E  {$$ = createTreeNode(0,2,NULL,'+',$1,$3);}
	| f  MIN  E  {$$ = createTreeNode(0,2,NULL,'-',$1,$3);}
	| f  DIV  E  {$$ = createTreeNode(0,2,NULL,'/',$1,$3);}
	| f  MUL  E  {$$ = createTreeNode(0,2,NULL,'*',$1,$3);}
	| f  LT   E  {$$ = createTreeNode(0,4,NULL,CLT,$1,$3);}
	| f  LTE  E  {$$ = createTreeNode(0,4,NULL,CLTE,$1,$3); }
	| f  GT   E  {$$ = createTreeNode(0,4,NULL,CGT,$1,$3);}
	| f  GTE  E  {$$ = createTreeNode(0,4,NULL,CGTE,$1,$3);}
	| f  EQ   E  {$$ = createTreeNode(0,4,NULL,CEQ,$1,$3);}
	| f  NEQ  E  {$$ = createTreeNode(0,4,NULL,CNEQ,$1,$3);}
	| f { $$ = $1;}
	| '(' E ')'	{ $$ = $2;}
	;

f:	ID {$$ = $1;}
	| ID '[' CONSTANT ']' {$1 = appendConstantVal($1,$3->val); $$ = $1;}
	| ID '[' ID ']' { $1 = appendVariableVal($1,$3->varname); $$ = $1; } 
	| ID '[' CONSTANT ']' '[' CONSTANT ']' {$1 = appendDoubleConst($1,$3->val,$6->val); $$ = $1;}
	| ID '[' ID ']' '[' CONSTANT ']' {$1 = appendVarConst($1,$3->varname,$6->val); $$ = $1;}
	| ID '[' CONSTANT ']' '[' ID ']' {$1 = appendConstVar($1,$3->val,$6->varname); $$ = $1;}
	| ID '[' ID ']' '[' ID ']' {$1 = appendDoubleVar($1,$3->varname,$6->varname); $$=$1;}
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
