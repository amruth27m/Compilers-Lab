#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "compilerlab.h"
#define PUSH 1
#define POP 2

int main(void){
	FILE *fp = fopen("stackinput.xsm","w");
	write_header(fp);
	
	system_call(fp,7,4096,0,0);

	system_call(fp,10,100,0,0);
	return 0;
}
