#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "exprtree.h"
#define PUSH 1
#define POP 2

reg_index register_count = 0;

reg_index getReg(){
	return ++register_count;
}

void freeReg(){
	if(register_count>0){
		register_count--;
	}
}

/*struct tnode* makeLeafNode(int n){
	struct tnode* temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}*/

/*struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode* r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}

int evaluate(struct tnode *t){
	if(t->op == NULL){
		return t->val;
	}
	else{
		switch(*(t->op)){
			case '+': return evaluate(t->left) + evaluate(t->right);
			case '-': return evaluate(t->left) - evaluate(t->right);
			case '*': return evaluate(t->left) * evaluate(t->right);
			case '/': return evaluate(t->left) / evaluate(t->right);


		}

	}
}

void print_tree(FILE *fp, struct tnode *t,int type){
	if(t->op == NULL){
		fprintf(fp, "%d",t->val);
		return;
	}
	else{
		switch(type){
		case 0:
			fprintf(fp,"%c",*(t->op));
			print_tree(fp,t->left,type);
			print_tree(fp,t->right,type);
			return;
		case 1:
			printf("reached here");	
			print_tree(fp,t->left,type);
			fprintf(fp,"%c",*(t->op));
			print_tree(fp,t->right,type);
			return;

		case 2: 
			print_tree(fp,t->left,type);
			print_tree(fp,t->right,type);
			fprintf(fp,"%c",*(t->op));
			return;
	
		}
	}

}

reg_index codeGen(struct tnode *t,FILE* fp){
	write_header(fp);
	int x = codeGenTree(t,fp);
	system_call(fp,5,x,0,0);
	system_call(fp,10,0,0,0);
	
}



void write_header(FILE *fp){
 fprintf(fp, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0);
}

reg_index codeGenTree(struct tnode *t, FILE* fp){
	if(t->op == NULL){
		int temp = getReg();
		fprintf(fp, "MOV R%d, %d\n",temp,t->val);
		return temp;
	}
	else {
		char operator[10];
		switch(*(t->op)){
			case '+':
				strcpy(operator,"ADD");
				break;
			case '-':
				strcpy(operator,"SUB");
				break;
			case '*':
				strcpy(operator,"MUL");
				break;
			case '/':
				strcpy(operator,"DIV");
				break;

		
		}

		int p = codeGenTree(t->left,fp);
		int q = codeGenTree(t->right,fp);
		if(p<q){
			fprintf(fp, "%s R%d, R%d\n",operator,p,q);
			freeReg();
			return p;
		}
		else {
			fprintf(fp, "%s R%d, R%d\n",operator,q,p);
			freeReg();
			return q;
		}
		
	}
}


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



void system_call(FILE *fp, int syscallno,int arg2,int opreg,int reg_backup ){
        struct sys_call_abi syscall;


        switch(syscallno){
                case WRITE:     syscall.sys_call_number = 5;
                                syscall.arg1 = -2;
                                syscall.arg2 = arg2;
                                syscall.interrupt_no = 7;
                                strcpy(syscall.sys_call_name,"Write");
                        //      syscall.arg3 = 
                                break;
                case READ:      syscall.sys_call_number = 7;
                                syscall.arg1 = -1;
                                syscall.arg2 = arg2;
                                syscall.interrupt_no = 6;
                                strcpy(syscall.sys_call_name, "Read");
                        //      syscall.arg3 = 
                                break;
                case EXIT:      syscall.sys_call_number = 10;
                                syscall.interrupt_no = 10;
                                syscall.arg1 = 0;
                                syscall.arg2 = 0;
                                strcpy(syscall.sys_call_name, "Exit");
                                break;
        }


        if(reg_backup){

                register_data_handle(PUSH,fp,0,19);

        }
	
	int temp_register = (syscall.arg2+1)%19;

        //push system call name
        fprintf(fp, "MOV R%d, \"%s\"\n",temp_register,syscall.sys_call_name);
        fprintf(fp, "PUSH R%d\n",temp_register);

        //push argument 1
        fprintf(fp, "MOV R%d, %d\n",temp_register,syscall.arg1);
        fprintf(fp, "PUSH R%d\n",temp_register);

        //push argument 2
        fprintf(fp, "PUSH R%d\n",syscall.arg2);

        //push argument 3 (empty value)
        fprintf(fp, "PUSH R0\n");

        //push empty storage value
        fprintf(fp, "PUSH R0\n");

        //transfer control to library
        fprintf(fp, "CALL 0\n");


}
*/

struct tnode* createTreeNode(int val, int type, char c, struct tnode *l, struct tnode *r){
	
	struct tnode* temp = malloc(sizeof(struct tnode));

	switch(type){
		case 0: temp->val = val;
			temp->type = type;
			temp->varname = temp->left = temp->right = NULL;
			break;
		case 1: temp->val = 0;
			temp->type = type;
			temp->varname = malloc(sizeof(char));
			*(temp->varname) = c;
			temp->left = temp->right = NULL;
			break;
		case 2: temp->val = 0;
			temp->type = type;
			temp->varname = NULL;
			switch(c){
				case '+': temp->nodetype = '+';
					  break;
				case '-': temp->nodetype = '-';
					  break;
				case '/': temp->nodetype = '/';
					  break;
				case '*': temp->nodetype = '*';
					  break;
				case '=': temp->nodetype = '=';
					  break;
				case 'r': temp->nodetype = 'r';
					  break;
				case 'w': temp->nodetype = 'w';
					  break;
			}
			temp->left = l;
			temp->right = r;
			break;
		case 3: temp->val = 0;
			temp->nodetype = 'b';
			temp->left = l;
			temp->right = r;
			break;
			

	}

	return temp;
}
