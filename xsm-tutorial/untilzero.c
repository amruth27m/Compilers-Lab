#include<stdio.h>
#include "compilerlab.h"

int main(void){
	FILE *fp = fopen("until_zero.xsm","w");
	write_header(fp);

	fprintf(fp, "MOV SP, 4097\n");
	fprintf(fp, "MOV R0, 4097\n");
	fprintf(fp, "MOV [R0], 0\n");
	
	fprintf(fp , "MOV R0, 4096\n");	
	system_call(fp,7,0,0,0);
	fprintf(fp ,"MOV R1, [4096]\n");
	fprintf(fp , "MOV R2, 0\n");
	fprintf(fp, "EQ R2, R1\n");
	fprintf(fp, "JNZ R2, 2098\n");
	fprintf(fp, "MOV R0, [4097]\n");
	fprintf(fp, "ADD R0, R1\n");
	fprintf(fp, "MOV [4097], R0\n");
	fprintf(fp, "JMP 2060\n");
	fprintf(fp, "MOV R0, [4097]\n");
	system_call(fp,5,0,0,0);
		

	system_call(fp,10,0,0,0);
	return 0;

}
