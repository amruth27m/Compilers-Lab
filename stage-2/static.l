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
[a-z] { yylval = createTreeNode(0,1,*yytext,NULL,NULL); return ID;}
[0-9]+ {  yylval = createTreeNode(atoi(yytext),0,NULL,NULL,NULL); return CONSTANT; }
"+" { return PLUS;}
"-" { return MIN; } 
"*" { return MUL;} 
"/" { return DIV;} 
"=" { return *yytext;}
"\n" { ylineno++; return *yytext;}
";" { return *yytext;}
[ ()] {return *yytext;}

. { printf("unknown character");}
%%

int yywrap(){
	return 1;
}
