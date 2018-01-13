#include<stdio.h>
int main(void){
	
	FILE *opfile;
	
	
	opfile = fopen("largest_of_3.xsm","w");

	fprintf(opfile, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0); 
	
	fprintf(opfile,"BRKP\n"); //2056 
 
	fprintf(opfile,"MOV R0,10\n");//58

	fprintf(opfile,"MOV R1, 11\n");//60
	
	fprintf(opfile,"MOV R2, 12\n");//62

	fprintf(opfile, "MOV R3, R0\n"); // 64 Take backup of R0

	fprintf(opfile,"LE R0,R1\n");//66

	fprintf(opfile,"JZ R0, 2074\n");//68

	fprintf(opfile , "LE R1, R2\n");//70

	fprintf(opfile , "JMP 2080\n");  //72

	fprintf(opfile , "MOV R0 , R3\n");//74  Reload the value of R0

	fprintf(opfile , "LE R0, R2\n"); //76




	return 0;

}
