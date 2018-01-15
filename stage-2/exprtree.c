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

*/
reg_index codeGen(struct tnode *t,FILE* fp){
	write_header(fp);
	int x = codeGenTree(t,fp);
	system_call(fp,10,0,0,0);
	
}



void write_header(FILE *fp){
 fprintf(fp, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0);
 fprintf(fp, "MOV SP, 4122\n");
}

reg_index codeGenTree(struct tnode *t, FILE* fp){

	if(t == NULL){
		return -1;
	}
	int p,loc,q;
	switch(t->type){
		case 0:
			p = getReg();
			fprintf(fp,"MOV R%d, %d\n",p,t->val);
			return p;
		case 1: 
			 p = getReg();
			 loc = 4096 + (int)(*(t->varname)) - 'a';
			fprintf(fp, "MOV R%d, [%d]\n",p,loc);
			return p;
		case 2:	
			switch(t->nodetype){
				case '+':	p = codeGenTree(t->left,fp);
						q = codeGenTree(t->right,fp);
						if(p<q){
							fprintf(fp,"ADD R%d, R%d\n",p,q);
							freeReg();
							return p;
						}
						else{
							fprintf(fp,"ADD R%d, R%d\n",q,p);
							freeReg();
							return q;
						}
						break;
				case '-':	p = codeGenTree(t->left,fp);
						q = codeGenTree(t->right,fp);
						if(p<q){
							fprintf(fp,"SUB R%d, R%d\n",p,q);
							freeReg();
							return p;
						}
						else{
							fprintf(fp,"SUB R%d, R%d\n",q,p);
							freeReg();
							return q;
						}
						break;
				case '*':	p = codeGenTree(t->left,fp);
						q = codeGenTree(t->right,fp);
						if(p<q){
							fprintf(fp,"MUL R%d, R%d\n",p,q);
							freeReg();
							return p;
						}
						else{
							fprintf(fp,"MUL R%d, R%d\n",q,p);
							freeReg();
							return q;
						}
						break;
				
				 case '/':	p = codeGenTree(t->left,fp);
						q = codeGenTree(t->right,fp);
						if(p<q){
							fprintf(fp,"DIV R%d, R%d\n",p,q);
							freeReg();
							return p;
						}
						else{
							fprintf(fp,"DIV R%d, R%d\n",q,p);
							freeReg();
							return q;
						}
						break;
				

				case '=' :
						p = codeGenTree(t->right,fp);
			 			loc = 4096 + (int)(*(t->left->varname)) - 'a';
						fprintf(fp,"MOV [%d], R%d\n",loc,p);
						break;
				case 'r' :	
			 			loc = 4096 + (int)(*(t->left->varname)) - 'a';
						p = getReg();
						fprintf(fp,"MOV R%d, %d\n",p,loc);
						system_call(fp,7,p,0,1);
						freeReg();
						register_data_handle(POP,fp,0,19);
						break;

				case 'w' :	p = codeGenTree(t->left,fp);
						system_call(fp,5,p,0,0);
						break;

			}
		
		case 3 : p = codeGenTree(t->left,fp);
			 q = codeGenTree(t->right,fp);
			 break;
	}

}

int evalarray[26];


int evalTree(struct tnode *t, FILE* fp){

	if(t == NULL){
		return 0;
	}
	int p,loc,q;
	switch(t->type){
		case 0:
			return t->val;
		case 1: 
			return evalarray[*(t->varname) - 'a'];
		case 2:	
			switch(t->nodetype){
				case '+':	
						return evalTree(t->left,fp) + evalTree(t->right,fp);
					
				case '-':
						return evalTree(t->left,fp) - evalTree(t->right,fp);
						
				case '*':	
						return evalTree(t->left,fp) * evalTree(t->right,fp);
				
				 case '/':	
				 		return evalTree(t->left,fp) / evalTree(t->right,fp);
				

				case '=' :
						p = evalTree(t->right,fp);
						evalarray[*(t->left->varname) - 'a'] = p;
						return 0;
				case 'r' :	
						scanf("%d",&evalarray[*(t->left->varname) - 'a']);
						break;

				case 'w' :	p = evalTree(t->left,fp);
						printf("%d",p);
						break;

			}
		
		case 3 : p = evalTree(t->left,fp);
			 q = evalTree(t->right,fp);
			 return -1;
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
                case WRTE:     syscall.sys_call_number = 5;
                                syscall.arg1 = -2;
                                syscall.arg2 = arg2;
                                syscall.interrupt_no = 7;
                                strcpy(syscall.sys_call_name,"Write");
                        //      syscall.arg3 = 
                                break;
                case RED:      syscall.sys_call_number = 7;
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
			temp->type = 3;
			temp->nodetype = 'b';
			temp->left = l;
			temp->right = r;
			break;
			

	}

	return temp;
}

void print_exp_tree(struct tnode* t){
	if(t == NULL){
		return;
	}
	switch(t->type){
		case 0:	printf("%d ",t->val);
			break;
		case 1:	printf("%c ",*(t->varname));
			break;

		case 2: printf("%c ", t->nodetype);
			print_exp_tree(t->left);
			print_exp_tree(t->right);
			break;
		case 3: printf(" Emprty node ");
			print_exp_tree(t->left);
			print_exp_tree(t->right);
			break;

	
	}	

}
