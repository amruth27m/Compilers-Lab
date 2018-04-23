%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int address = 2040;
int label_table[100];
int phase;
FILE *target_file;
%}

NUM [0-9]+

%%
("L"){NUM}(":\n") {yyleng = yyleng - 1;
                   label_table[atoi(yytext+1)] = address;}

("L"){NUM} {if(phase == 2) {
              fprintf(target_file, "%d", label_table[atoi(yytext + 1)]);
            } else {
            fprintf(target_file, "%s", yytext);
            }
           }

"\n" {address = address + 2;
      fprintf(target_file, "%s", yytext);}

. fprintf(target_file, "%s", yytext);
%%

int yywrap() {
if(phase == 1) {
  fclose(target_file);
  yyin = fopen("intermediate_output.xsm","r");
  target_file = fopen("output.xsm","w");
  phase = 2;
  return 0;
}
return 1;
}

int main() {
  phase = 1;
  yyin = fopen("out","r");
  target_file = fopen("intermediate_output.xsm","w");
  yylex();
  fclose(target_file);
  return 0;
}
