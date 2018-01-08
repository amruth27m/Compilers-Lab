%{
#include<stdio.h>

%}

sc "//"
mc "/\*"
mcend "\*/"
newline [\n]

%%

{sc}. {printf("single line comment found");}
({mc}^({mcend})) {printf("multiline comment detected");}

%%

int yywrap(){
	
	return 1;
}

int main(){
yylex();
return 0;
}
