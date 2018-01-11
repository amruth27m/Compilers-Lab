%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

digit [0-9]
newline [\n]

%%

{digit}+	{	 yylval = atoi(yytext);
			return DIGIT;
		}
{newline}	{	return NEWLINE;	}

'+'	{ return *yytext;	}
'-'	{ return *yytext;	}
'*'	{ return *yytext;	}
[()] 	{ return *yytext;	}
. 	{ return *yytext;	}
%%

int yywrap(){
	return 1;
}
