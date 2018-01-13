#include<stdio.h>
#include "compilerlab.h"

int main(void){
	FILE *fp = fopen("library_ip.xsm","w");
	write_header(fp);

	fprintf(fp, "MOV SP, 4095\n");
	
	system_call(fp,5,100,0,0);
	system_call(fp,10,0,0,0);
	return 0;

}
