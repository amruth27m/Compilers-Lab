%{
	#include<stdio.h>
	char *file1;
	int count = 0;
%}

%%

[0-9]+ 	printf("number");

%%

int yywrap()
{
  	if(count == 0)
  	{
  		yyin = stdin;
		count++;
    		return 0;
  	}
  	else
  		return 1;
}

int main()
{
  	yylex();
  	return 1;
}
