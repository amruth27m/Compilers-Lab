#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "compilerlab.h"
#define PUSH 1
#define POP 2
#define WRITE 5
#define READ 7
#define EXIT 10

void register_data_handle(int flag, FILE* opfile,int begin , int end ){
        char *action = malloc(sizeof(char)*4);
        if(flag == PUSH){
    
                strcpy(action , "PUSH");
		for(int counter = begin; counter <= end; counter++){
               		 fprintf(opfile, "%s R%d\n",action,counter);
        	}

        }
        else if(flag == POP){

                strcpy(action, "POP");
		for(int counter = end; counter >= begin; counter--){
                	fprintf(opfile, "%s R%d\n",action,counter);
        	}
        }
    
        

}

void write_header(FILE *opfile){
        fprintf(opfile, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0);
}

struct sys_call_abi{
	int sys_call_number,arg1,arg2,arg3,interrupt_no;
	char sys_call_name[10];
};

void system_call(FILE *fp, int syscallno,int arg2,int opreg,int reg_backup){
	struct sys_call_abi syscall;
	


	switch(syscallno){
		case WRITE:	syscall.sys_call_number = 5;
				syscall.arg1 = -2;
				syscall.arg2 = arg2;
				syscall.interrupt_no = 7;
				strcpy(syscall.sys_call_name,"Write"); 
			//	syscall.arg3 = 
				break;
		case READ:	syscall.sys_call_number = 7;
				syscall.arg1 = -1;
				syscall.arg2 = arg2;
				syscall.interrupt_no = 6;
				strcpy(syscall.sys_call_name, "Read");
			//	syscall.arg3 = 
				break;
		case EXIT:	syscall.sys_call_number = 10;
				syscall.interrupt_no = 10;
				syscall.arg1 = 0;
				syscall.arg2 = 0;
				strcpy(syscall.sys_call_name, "Exit");
				break;
	}


	if(reg_backup){

		register_data_handle(PUSH,fp,0,19);
	
	}
	//push system call name
	fprintf(fp, "MOV R2, \"%s\"\n",syscall.sys_call_name);
        fprintf(fp, "PUSH R2\n");

	//push argument 1
        fprintf(fp, "MOV R2, %d\n",syscall.arg1);
        fprintf(fp, "PUSH R2\n");

	//push argument 2
        fprintf(fp, "MOV R0, %d\n",syscall.arg2);
        fprintf(fp, "PUSH R0\n");

        //push argument 3 (empty value)
        fprintf(fp, "PUSH R0\n");

        //push empty storage value
        fprintf(fp, "PUSH R0\n");

	//transfer control to library
        fprintf(fp, "CALL 0\n");


	if(reg_backup){
		register_data_handle(POP,fp,0,19);
	}

}



void pop_after_syscall(FILE* fp,short syscallno, short op_register){
	
	//poping and savind return value
	fprintf(fp,"POP R%d\n",op_register);
	
	//pop and discard arguments and function code
	for(int i = 0; i<4;i++){
		fprintf(fp, "POP R%d\n",(op_register+1)%19);
	}
}
