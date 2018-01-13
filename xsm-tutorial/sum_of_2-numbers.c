#include<stdio.h>
int main(void){
	FILE *opfile;
	opfile = fopen("sum.xsm","w");
	fprintf(opfile, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0); 
	fprintf(opfile, "BRKP\n");
	fprintf(opfile, "MOV R0, 3\n");
	fprintf(opfile, "MOV R1, 2\n");
	fprintf(opfile , "ADD R0, R1\n");
	return 0;
}
