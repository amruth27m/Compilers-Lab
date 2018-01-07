/* Declarations */
%option noyywrap
number [0-9]+

%%

{number} {return atoi(yytext);}

%%

int main()
{
	int num = yylex();
	printf("Found: %d",num);
	return 1;
}
