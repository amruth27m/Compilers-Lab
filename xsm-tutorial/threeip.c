#include<stdio.h>
#include "compilerlab.h"

int main(void){
	FILE *fp = fopen("library_ip.xsm","w");
	write_header(fp);

	fprintf(fp, "MOV SP, 4098\n");
	fprintf(fp , "MOV R0, 4096\n");	
	system_call(fp,7,0,0,0);

	fprintf(fp , "MOV R0, 4097\n");	
	system_call(fp,7,0,0,0);

	fprintf(fp , "MOV R0, 4098\n");	
	system_call(fp,7,0,0,0);
	fprintf(fp,"MOV R0, [4096]\n");
	system_call(fp,5,0,0,0);
	fprintf(fp,"MOV R1, [4097]\n");
	system_call(fp,5,1,0,0);
	fprintf(fp,"MOV R1, [4098]\n");
	system_call(fp,5,1,0,0);


	system_call(fp,10,0,0,0);
	return 0;

}
