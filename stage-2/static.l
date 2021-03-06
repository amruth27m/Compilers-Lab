%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
#include "custom.h"
int ylineno = 0;
extern int decl_block;
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
(decl) {decl_block = 1; return DECL;}
(enddecl) { decl_block = 0;return ENDDECL;}
(int) { yylval = 0; return INT;}
(str) {yylval = 1; return STR;}
[a-z]+ { char *s = malloc(sizeof(char)*yyleng); strcpy(s,yytext); yylval = createTreeNode(0,1,s,0,NULL,NULL); return ID;}
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
"[" {return *yytext;}
"]" {return *yytext;}
[(), ] {return *yytext;}

. { printf("unknown character");}
%%

int yywrap(){
	return 1;
}
