%option noyywrap
%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
	#include"label_tr.h"
	#include"label_tr.c"
	extern FILE *yyin;
	FILE* fout,*ftemp,*fin;
	int pass=1;
	int currLine = 2048;
%}
%%
(.)*:[\n] {
	if(pass==1){
		char t[2];
		for(int i = 1;yytext[i]!='\0';i++){
			t[i-1] = yytext[i];
		}
		insert(atoi(t),currLine);
	}
}


(J(.)*[\n]) {
				
	if(pass == 1){
		fstrcpy(ftemp, yytext);
	} else {
		int i,j, labelNo;				
		char tempS[50];
		for(i=0; i<yyleng && yytext[i]!='L' && yytext[i]!='F' ; i++){
			tempS[i] = yytext[i];
		}
		tempS[i]='\0';
		int k = i+1,in_count=0;
		char a[3];

		while(yytext[k]!='\0'){
			a[in_count++] = yytext[k++];
		}
		a[in_count] = '\0';
		labelNo = atoi(a);
			fprintf(fout,"%s%d\n",tempS,search(labelNo));
		}
		incLine();
}



.*[\n] {	
	if(pass == 1){
		fstrcpy(ftemp, yytext);
	} else if(pass==2){
		fstrcpy(fout, yytext);
	}
		incLine();
}

%%


void incLine(){
	if(currLine>=2056){
		currLine=currLine+2;
		return;
	} else {
		currLine++;
		return;
	}
}

void fstrcpy(FILE *fp, char* s){
	int i;
	char ch;
	for(i=0;i<strlen(s);i++){
      	ch = s[i];
       	putc(ch, fp);
     	}
}

int main(int argc, char* argv[])
{	char c;
	if(argc > 2){
		ftemp =fopen("temp", "w");
		yyin = fopen(argv[1], "r");
	} else {
		return 0;
	}
	yylex();
	currLine=2048;
	pass=2;
	display();
	fclose(ftemp);
	fout = fopen(argv[2], "w");
	fin = fopen("temp", "r");
	yyin = fin;
	if (!yyin) {
		return 1;
		}
	yylex();
	return 1;
}

