
%{
/*** Auxiliary declarations section ***/

#include<stdio.h>
#include<stdlib.h>

/* Custom function to print an operator*/

/* Variable to keep track of the position of the number in the input */
int nestcount = 0;
%}

 /*** YACC Declarations section ***/
%token DIGIT IF THEN ELSE ID
%left '+'
%left '*'
%left '='
%left '!'
%%

/*** Rules Section ***/
start : if_then_else '\n'		{exit(1);}
      ;

if_then_else: IF '(' cond ')' THEN if_then_else ELSE if_then_else      {printf("+");}
    | IF '(' cond ')' THEN cond ELSE if_then_else	{printf("case2");}
    | IF '(' cond ')' THEN cond ELSE cond		{printf("case3");}
    | IF '(' cond ')' THEN if_then_else ELSE cond	{printf("case4");}
    ;

cond: ID '=' ID
    | ID '!' ID
    ;

%%


/*** Auxiliary functions section ***/


yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        pos++;
        return ID;
    }
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else {
        if(c == 'i');
	c = getchar();
	if(c == 'f');
	return IF
    }
}

main()
{
	yyparse();
	return 1;
}
