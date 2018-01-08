%{

#include<stdio.h>
int floatcount = 0;
int integercount = 0;
%}
integer [0-9]+
%%
({integer}+\.+{integer}+) {floatcount++;}
({integer}+) {integercount++;}

%%
int main(){
yylex();
printf("\nFloat count = %d",floatcount);
printf("\nInteger count = %d",integercount);


}
int yywrap(){
return 1;
}
