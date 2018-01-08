%{
#include<stdio.h>

%}

uc [A-Z]
space [ \n\t]

%%

({uc}{uc}{uc}{space}+) {printf("found %s\n",yytext);}

%%
int yywrap(){
return 1;
}

int main(){
yylex();
return 0;
}
