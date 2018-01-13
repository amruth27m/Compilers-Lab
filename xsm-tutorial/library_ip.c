#include<stdio.h>
#include "compilerlab.h"

int main(void){
	FILE *fp = fopen("library_ip.xsm","w");
	write_header(fp);

	fprintf(fp, "MOV SP, 4095\n");
	
	fprintf(fp, "MOV R2, \"Exit\"\n");
	fprintf(fp , "PUSH R2\n");

	fprintf(fp , "MOV R2, -2\n");
	fprintf(fp , "PUSH R2\n");

	fprintf(fp, "MOV R0, 100\n");
	fprintf(fp, "PUSH R0\n");

	fprintf(fp, "PUSH R0\n");
	fprintf(fp, "PUSH R0\n");

	fprintf(fp, "CALL 0\n");

	return 0;

}
