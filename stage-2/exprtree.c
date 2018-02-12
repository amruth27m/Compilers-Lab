#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "exprtree.h"
#define PUSH 1
#define POP 2

reg_index _register_count = 0;
label_index _label_count = 0;
int _evalarray[26];


//function to get the next label
label_index getLabel(){
	return _label_count++;
}

//function to get a free register
reg_index getReg(){
	return _register_count++;
}

//function to free the largest occupied register
void freeReg(){
	if(_register_count>0){
		_register_count--;
	}
}

//function to get the label of current break position
int current_break(){
	continue_top--;
	return break_stack[break_top--];
}

//function to get the label of the current continue position
int current_continue(){
	return continue_stack[continue_top];
}


void  codeGen(struct tnode *t,FILE* fp){
	write_header(fp);
	int x = codeGenTree(t,fp);
	system_call(fp,10,0,0);
	
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
		case 0: //constants
			p = getReg();
			fprintf(fp,"MOV R%d, %d\n",p,t->val);
			return p;
		case 1: 
			//variables
			 p = getReg();
			 loc = 4096 + (int)((t->varname)[0]) - 'a';
			fprintf(fp, "MOV R%d, [%d]\n",p,loc);
			return p;
		case 2:	
			//arithemetic expressions
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
						}
			break;
		case 3 : //empty node
			 p = codeGenTree(t->left,fp);
			 q = codeGenTree(t->right,fp);
			 break;

		case 4: //logical operators
			p = codeGenTree(t->left,fp);
			q = codeGenTree(t->right,fp);
			int opreg,ipreg;
			if(p<q){
				opreg = p;
				ipreg = q;
			}
			else{
				opreg = q;
				ipreg = p;
			}

			switch(t->nodetype){
				case CLT:
					fprintf(fp,"LT R%d, R%d\n",opreg,ipreg);
					break;
				case CLTE:

					fprintf(fp,"LE R%d, R%d\n",opreg,ipreg);
					break;
				case CGT:

					fprintf(fp,"GT R%d, R%d\n",opreg,ipreg);
					break;
				case CGTE:

					fprintf(fp,"GE R%d, R%d\n",opreg,ipreg);
					break;
				case CEQ:

					fprintf(fp,"EQ R%d, R%d\n",opreg,ipreg);
					break;
				case CNEQ:

					fprintf(fp,"NE R%d, R%d\n",opreg,ipreg);
					break;

			}
			freeReg();
			return opreg;
			break;
		
		case 5:
			//read and write
			switch(t->nodetype){
			
				case 'r' :	
			 			loc = 4096 + (int)(((t->left->varname)[0])) - 'a';
						p = getReg();
						fprintf(fp,"MOV R%d, %d\n",p,loc);
						system_call(fp,7,p,0);
						freeReg();
						break;

				case 'w' :	p = codeGenTree(t->left,fp);
						system_call(fp,5,p,0);
						break;


			
			}
			break; 
		case 6:
			switch(t->nodetype){
				case 1:
					p = codeGenTree(t->left,fp);
					int elseLabel = getLabel();
					fprintf(fp,"JZ R%d, L%d\n",p,elseLabel);
					q = codeGenTree(t->middle,fp);

					int afterElseLabel = getLabel();
					fprintf(fp,"JMP L%d\n",afterElseLabel);
					fprintf(fp,"L%d:\n",elseLabel);
					q = codeGenTree(t->right,fp);
					fprintf(fp,"L%d:\n",afterElseLabel);
					break;
				case 2:;
					int whileStartLabel = getLabel();
					int whileEndLabel = getLabel();
					
					break_stack[++break_top] = whileEndLabel;
					continue_stack[++continue_top] = whileStartLabel;

					fprintf(fp,"L%d:\n",whileStartLabel);
					p = codeGenTree(t->left,fp);
					fprintf(fp,"JZ R%d, L%d\n",p,whileEndLabel);
					q = codeGenTree(t->right,fp);
					fprintf(fp,"JMP L%d\n",whileStartLabel);
					fprintf(fp,"L%d:\n",whileEndLabel);
					
					break_top--;
					continue_top--;

					break;
				case 3:
					p = codeGenTree(t->left,fp);
					int afterThenLabel = getLabel();
					fprintf(fp,"JZ R%d, L%d\n",p,afterThenLabel);
					q = codeGenTree(t->right,fp);
					fprintf(fp,"L%d:\n",afterThenLabel);
					break;

			}
			break;
		case 7:
			switch(t->nodetype){
				case 0:
					//break;
					fprintf(fp,"JMP L%d\n",current_break());
					break;
				case 1:
					fprintf(fp,"JMP L%d\n",current_continue());
					break;
					//continue;
			}
			break;

					
	}

}



int evalTree(struct tnode *t, FILE* fp){

	if(t == NULL){
		return 0;
	}
	int p,loc,q;
	switch(t->type){
		case 0:
			return t->val;
		case 1: 
			return _evalarray[*(t->varname) - 'a'];
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
						_evalarray[*(t->left->varname) - 'a'] = p;
						return 0;
		
			}

		case 3 : p = evalTree(t->left,fp);
			 q = evalTree(t->right,fp);
			 return -1;
		case 4: 
			 p = evalTree(t->left,fp);
			 q = evalTree(t->right,fp);
			 switch(t->nodetype){
				 case CLT:
					 if(p<q)	return 1; else return 0;
					 break;
				 case CLTE: 	if(p<=q) return 1; else return 0;
							break;
				 case CGT:	if(p>q) return 1; else return 0;
							break;
				 case CGTE:	if(p>=q) return 1; else return 0;
							break;
				 case CEQ:	if(p==q) return 1;else return 0;
							break;
				 case CNEQ: 	if(p!=q) return 1; else return 0;
							break;
			 }
			 break;

		case 5:
			 switch(t->nodetype){
				 
				 case 'r' :	
						 scanf("%d",&_evalarray[*(t->left->varname) - 'a']);
						 break;

				 case 'w' :	p = evalTree(t->left,fp);
						printf("%d",p);
						break;


			 }


		case 6: switch(t->nodetype){
				case 1:
					p = evalTree(t->left,fp);
					if(p!=0){
						q = evalTree(t->middle,fp);
						return 1;	
					}
					else{
						q = evalTree(t->right,fp);
						return 1;
					}
					break;

				case 2:
					p = evalTree(t->left,fp);
					while(p!=0){
						q = evalTree(t->right,fp);
						p = evalTree(t->left,fp);
					}

			}
			break;
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



void system_call(FILE *fp, int syscallno,int arg2,int opreg){
        struct sys_call_abi syscall;


        switch(syscallno){
                case WRITE_SYSCALL: 
				syscall.sys_call_number = 5;
                                syscall.arg1 = -2;
                                syscall.arg2 = arg2;
                                syscall.interrupt_no = 7;
                                strcpy(syscall.sys_call_name,"Write");
                        //      syscall.arg3 = 
                                break;
                case READ_SYSCALL: 
				syscall.sys_call_number = 7;
                                syscall.arg1 = -1;
                                syscall.arg2 = arg2;
                                syscall.interrupt_no = 6;
                                strcpy(syscall.sys_call_name, "Read");
                        //      syscall.arg3 = 
                                break;
                case EXIT_SYSCALL:      
				syscall.sys_call_number = 10;
                                syscall.interrupt_no = 10;
                                syscall.arg1 = 0;
                                syscall.arg2 = 0;
                                strcpy(syscall.sys_call_name, "Exit");
                                break;
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

struct tnode* createBreakNode(int type){
	struct tnode *temp = malloc(sizeof(struct tnode));
	temp->type = 7;
	switch(type){
		case 0:
			temp->nodetype = 0;
			break;
		case 1:
			temp->nodetype = 1;
			break;
	}
	return temp;
}

struct tnode* createTreeNode(int val, int type, char *c,int nodetype, struct tnode *l, struct tnode *r){
	
	struct tnode* temp = malloc(sizeof(struct tnode));

	switch(type){
		case 0: //constants 
			temp->val = val;
			temp->type = type;
			temp->left = temp->right = NULL;
			break;
		case 1: //variables
			temp->val = 0;
			temp->type = type;
			temp->varname = malloc(sizeof(char)*20);
			strcpy(temp->varname,c);
			temp->left = temp->right = NULL;
			break;
		case 2: //arithemetic exp
			if(l->type==4||r->type==4){
				printf("type mismatch\n");
				exit(-1);
			}
			temp->val = 0;
			temp->type = type;
			temp->nodetype = nodetype;
			temp->left = l;
			temp->right = r;
			break;
		case 3: //empty nodes
			temp->val = 0;
			temp->type = type;
			temp->nodetype = 'b';
			temp->left = l;
			temp->right = r;
			break;
		case 4: //logical operators
			temp->type = type;
			temp->nodetype = nodetype;
			temp->left = l;
			temp->right = r;
			break;
			

		case 5: //read and write
			temp->type = type;
			temp->nodetype = nodetype;
			temp->left = l;
			temp->right = r;
			break;
	}

	return temp;
}

struct tnode* createConditionalNode(int condition,struct tnode* l,struct tnode*m,struct tnode*r){
	struct tnode* temp = malloc(sizeof(struct tnode));
	if(l->type!=4){
		printf("type mismatch\n");
		exit(-1);

	}
	temp->type = 6;
	switch(condition){
		case CIF:

			if(m->type==4||r->type==4){
				printf("Type mismatch for if\n");
				exit(-1);
			}
			temp->left = l;
			temp->middle = m;
			temp->right = r;
			temp->nodetype = 1;
			break;

		case CWHILE:
			if(r->type==4){
				printf("Type mismatch for if\n");
				exit(-1);
			}
			temp->left = l;
			temp->right = r;
			temp->nodetype = 2;
			break;

		case CIF_ELSE:
			if(m->type==4){
				printf("Type mismatch for if\n");
				exit(-1);
			}
			temp->left = l;
			temp->right = m;
			temp->nodetype = 3;
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
