%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
int ylineno = 0;


%}


%%

(begin) { return BEG; }
(end;) { return END;}
(read) {  return READ;}
(write) { return WRITE; }
(if) { return IF;}
(then) { return THEN;}
(else) { return ELSE;}
(endif) { return ENDIF;}
(while) { return WHILE;}
(do) 	{ return DO;}
(break) { return BREAK;}
(continue) { return CONTINUE;}
(endwhile) {return ENDWHILE;}
(decl) {return DECL;}
(enddecl) {return ENDDECL;}
(int) { yylval = 0; return INT;}
(str) {yylval = 1; return STR;}
[a-z] { char *s = malloc(sizeof(char)); strcpy(s,yytext); yylval = createTreeNode(0,1,s,0,NULL,NULL); return ID;}
[0-9]+ {  yylval = createTreeNode(atoi(yytext),0,0,NULL,NULL,NULL); return CONSTANT; }
"+" { return PLUS;}
"-" { return MIN; } 
"*" { return MUL;} 
"/" { return DIV;}
"<" { return LT;}
">" { return GT;}
(<=) { return LTE;}
(>=) { return GTE;}
(!=) { return NEQ;}
(==) {return EQ;}
"=" { return *yytext;}
"\n" { ylineno++; return *yytext;}
";" { return *yytext;}
[(), ] {return *yytext;}

. { printf("unknown character");}
%%

int yywrap(){
	return 1;
}
