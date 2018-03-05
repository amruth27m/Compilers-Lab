#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "exprtree.h"
#include "custom.h"
#define PUSH 1
#define POP 2

int log = 1;
reg_index _register_count = 0;
label_index _label_count = 0;
int _evalarray[26];

struct Gsymbol *gsymbol_begin = NULL;
struct Gsymbol *gsymbol_cur = NULL;
binding_addr = 4096;


struct varIndex *revShape(struct varIndex *shape){
	struct varIndex *temp = shape;
	while(shape!=NULL){
		
	}
}

void inc_binding_addr(int count){
	binding_addr += count;
}

int get_binding_addr(){
	return binding_addr;
}


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


struct tnode *appendConstantVal(struct tnode* node, int constant){
	
	checkIndexValidity(node->varname,constant,1);
	printf("Appending %d to %s\n",constant,node->varname);

	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = INTEGER_INDEX;
	temp->index = constant;
	node->arrayIndex = temp;
	return node;
}

struct tnode *appendDoubleVar(struct tnode* node, char *varname_x,char *varname_y){

	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = VARIABLE_INDEX;
	temp->name = malloc(sizeof(char)*strlen(varname_x));
	strcpy(temp->name,varname_x);
	node->arrayIndex = temp;


	struct varIndex *temp1 = malloc(sizeof(struct varIndex));
	temp1->type = VARIABLE_INDEX;
	temp1->name = malloc(sizeof(char)*strlen(varname_y));
	strcpy(temp1->name,varname_y);

	temp->next = temp1;
	return node;
}

struct tnode *appendDoubleConst(struct tnode* node,int index_x,int index_y){
	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = INTEGER_INDEX;
	temp->index = index_x;
	node->arrayIndex = temp;

	struct varIndex *temp1 = malloc(sizeof(struct varIndex));
	temp1->type = INTEGER_INDEX;
	temp1->index = index_y;
	
	temp->next = temp1;
	return node;
}

struct tnode *appendConstVar(struct tnode* node,int index,char *varname){
	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = INTEGER_INDEX;
	temp->index = index;
	node->arrayIndex = temp;

	struct varIndex *temp1 = malloc(sizeof(struct varIndex));
	temp1->type = VARIABLE_INDEX;
	temp1->name = malloc(sizeof(char)*strlen(varname));
	strcpy(temp1->name,varname);
	temp->next = temp1;
	return node;
}

struct tnode *appendVarConst(struct tnode* node,char *varname, int index){
	struct varIndex *temp1 = malloc(sizeof(struct varIndex));
	temp1->type = VARIABLE_INDEX;
	temp1->name = malloc(sizeof(char)*strlen(varname));
	strcpy(temp1->name,varname);
	node->arrayIndex = temp1;

	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = INTEGER_INDEX;
	temp->index = index;
	node->arrayIndex = temp;
	temp1->next = temp;

	return node;

}

struct tnode *appendVariableVal(struct tnode* node,char *varname){
	if(log){
		printf("Appending %s to %s index\n",varname,node->varname);
	}
	struct varIndex *temp = malloc(sizeof(struct varIndex));
	temp->type = VARIABLE_INDEX;
	temp->name = malloc(sizeof(char)*strlen(varname));
	strcpy(temp->name,varname);
	node->arrayIndex = temp;
	return node;
}

void checkIndexValidity(char *varname,int constant,int dimension){
	struct Gsymbol *temp = lookup(varname);
	struct varIndex *temp1 = temp->shape;	
	int count = 1;
	while(count<dimension){
		if(temp1 == NULL){
			printf("Invalid index %d for %s\n",constant, varname);
			exit(-1);
		}
		else{
			count++;
			temp1 = temp1->next;
		}

	}
	if(temp1->index<=constant){
		printf("Out of boundary index %d for %s\n",constant,varname);
		exit(-1);
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

struct Gsymbol *lookup(char *name){
	struct Gsymbol *iter = gsymbol_begin;
	while(iter!=NULL){
		if(strcmp((iter->varname),name) == 0)
			return iter;
		iter = iter->next;
	}
	return iter;
}
void createDeclarations(int type,struct varList *list){
	while(list!=NULL){
		if(lookup(list->name)!=NULL){
			printf("%s already declared\n",list->name);
			list = list->next;
			continue;
		}
		else{
			initVariable(list->name,type,(list->index));
			list = list->next;
		}
	}	
}

void printSymbolTable(){
	struct Gsymbol *iter = gsymbol_begin;
	printf("\n");
	while(iter!=NULL){
		printf("%s %d %d %d",iter->varname,iter->type,iter->size,iter->binding);
		struct varIndex *temp = iter->shape;
		int size = 1;
		while(temp!=NULL){
			size *= temp->index;
			temp = temp->next;
		}
		printf(" %d\n",size);
		iter = iter->next;
	}
}

void initVariable(char *name, int type,struct varIndex *shape){

	struct Gsymbol *temp = malloc(sizeof(struct Gsymbol));
	(temp->varname) = malloc(sizeof(char)*strlen(name));
	strcpy((temp->varname),name);
	temp->type = type;
	
	//iterating through dimensions
	struct varIndex *iter = shape;
	int count = 1,dim = 0;
	while(iter!=NULL){
		count *= iter->index;
		dim++;
		iter = iter->next;
	}

	temp->size = count;
	temp->shape = malloc(sizeof(struct varIndex));
	temp->shape = shape;

	temp->binding = get_binding_addr();
	inc_binding_addr(temp->size);

	if(gsymbol_cur == NULL){
		gsymbol_begin = gsymbol_cur = temp;
	}
	else{
		(gsymbol_cur->next) = temp;
		gsymbol_cur = temp;
	}
}

struct varList *createVarNode(struct tnode *temp){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(temp->varname));
	strcpy((dummy->name),temp->varname);
	dummy->next = NULL;
	dummy->index = malloc(sizeof(struct varIndex));
	(dummy->index)->index = 1;
	return dummy;
}

struct varList *linkVarNode(struct tnode *id, struct varList *rest){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(id->varname));
	strcpy((dummy->name),id->varname);
	dummy->next = rest;
	dummy->index = malloc(sizeof(struct varIndex));
	(dummy->index)->index = 1;
	return dummy;
}

struct varList *linkMatrixNode(struct tnode *temp, int index_x,int index_y,struct varList *rest){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(temp->varname));
	strcpy(dummy->name,temp->varname);
	
	struct varIndex *arraySize_x = malloc(sizeof(struct varIndex));
	arraySize_x->type = INTEGER_INDEX;
	arraySize_x->index = index_x;

	struct varIndex *arraySize_y = malloc(sizeof(struct varIndex));
	arraySize_y->type = INTEGER_INDEX;
	arraySize_y->index = index_y;
	arraySize_y->next = NULL;
	arraySize_x->next = arraySize_y;

	dummy->next = rest;
	dummy->index = arraySize_x;
	
	return dummy;


}

struct varList *createMatrixNode(struct tnode *temp,int index_x,int index_y){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(temp->varname));
	strcpy(dummy->name,temp->varname);
	
	struct varIndex *arraySize_x = malloc(sizeof(struct varIndex));
	arraySize_x->type = INTEGER_INDEX;
	arraySize_x->index = index_x;

	struct varIndex *arraySize_y = malloc(sizeof(struct varIndex));
	arraySize_y->type = INTEGER_INDEX;
	arraySize_y->index = index_y;
	arraySize_y->next = NULL;
	arraySize_x->next = arraySize_y;

	dummy->next = NULL;
	dummy->index = arraySize_x;

	return dummy;

}

struct varList *createArrayNode(struct tnode *temp,int index){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(temp->varname));
	strcpy(dummy->name,temp->varname);
	struct varIndex *arraySize = malloc(sizeof(struct varIndex));
	arraySize->type = INTEGER_INDEX;
	arraySize->index = index;
	arraySize->next = NULL;
	dummy->next = NULL;
	dummy->index = arraySize;
	return dummy;
}

struct varList *linkArrayNode(struct tnode *temp,int index,struct tnode *rest){
	struct varList *dummy = malloc(sizeof(struct varList));
	dummy->name = malloc(sizeof(char)*strlen(temp->varname));
	strcpy(dummy->name,temp->varname);
	struct varIndex *arraySize = malloc(sizeof(struct varIndex));
	arraySize->type = INTEGER_INDEX;
	arraySize->index = index;
	arraySize->next = NULL;
	dummy->next = rest;
	dummy->index = arraySize;
	return dummy;
}

void  codeGen(struct tnode *t,FILE* fp){
	write_header(fp);
	codeGenTree(t,fp);
	system_call(fp,10,0,0);
	
}



void write_header(FILE *fp){
	fprintf(fp, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0);
 	fprintf(fp, "MOV SP, 4122\n");
}

int dim_mul(int dim,char *varname){
	if(dim == 1) 
		return 1;
	struct varList *shape = (lookup(varname)->shape);
	dim--;
	while(dim - 1){
		shape = shape->next;
	}
	return shape->index;
}



reg_index codeGenTree(struct tnode *t, FILE* fp){
	
	//if the link is null
	if(t == NULL){
		return -1;
	}


	int p,loc,q;
	
	switch(t->type){
		case NUMERIC_CONSTANT: //constants
			p = getReg();
			fprintf(fp,"MOV R%d, %d\n",p,t->val);
			return p;

		case VARIABLE: 
			//variables
			p = getReg();
			struct varIndex *iter = t->arrayIndex;
			loc = t->Gentry->binding;
			fprintf(fp, "MOV R%d, %d\n",p,loc);
			int dim = 1;
			while(iter!=NULL){
				switch(iter->type){
					
					case INTEGER_INDEX:
						
						fprintf(fp,"ADD R%d, %d\n",p,iter->index*dim_mul(dim,t->varname));
						break;

					case VARIABLE_INDEX:
						printf("");
						struct Gsymbol *temp_index = lookup(iter->name);
						int temp_reg = getReg();
						fprintf(fp,"MOV R%d, [%d]\n",temp_reg,temp_index->binding);
						fprintf(fp,"ADD R%d, R%d\n",p,temp_reg);
						freeReg();
						break;


				}
				iter = iter->next;
				dim++;
			}
			fprintf(fp, "MOV R%d, [R%d]\n",p,p);


			return p;

		case ARITHEMETIC_EXP:	
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
						printf("The value is %d",t->right->val);
						p = codeGenTree(t->right,fp);
			 			loc = t->left->Gentry->binding;
						struct varIndex *iter = t->left->arrayIndex;
						int temp_reg = getReg();
						fprintf(fp,"MOV R%d, %d\n",temp_reg,loc);
						int dim = 1;
						while(iter!=NULL){
							switch (iter->type){
								
								case INTEGER_INDEX:
									fprintf(fp,"ADD R%d, %d\n",temp_reg,iter->index*dim_mul(dim,t->left->varname));
									break;
								case VARIABLE_INDEX:
									printf("");
									struct Gsymbol *var_loc = lookup(iter->name);
									
									int temp_reg2 = getReg();
									fprintf(fp,"MOV R%d, [%d]\n",temp_reg2,var_loc->binding);
									fprintf(fp,"ADD R%d, R%d\n",temp_reg,temp_reg2);
									freeReg();
									break;
									
							}
							iter = iter->next;
							dim++;
						}

						fprintf(fp,"MOV [R%d], R%d\n",temp_reg,p);
						freeReg();
						freeReg();
						break;
			}
			break;

		case EMPTY_NODE: //empty node
			 p = codeGenTree(t->left,fp);
			 q = codeGenTree(t->right,fp);
			 break;

		case LOGICAL_EXP: //logical operators
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
		
		case READ_WRITE:
			//read and write
			switch(t->nodetype){
			
				case 'r' :	
						printf("");
						struct varIndex *iter = t->left->arrayIndex;
						int loc = t->left->Gentry->binding;
						p = getReg();
						fprintf(fp,"MOV R%d, %d\n",p,loc);
						int dim = 1;
						while(iter!=NULL){
							switch(iter->type){
								case INTEGER_INDEX:
									fprintf(fp,"ADD R%d, %d\n",p,iter->index*dim_mul(dim,t->left->varname));
									break;
								
								case VARIABLE_INDEX:
									printf("");
									int temp_reg = getReg();
									struct Gsymbol *var_loc = lookup(iter->name);
									fprintf(fp,"MOV R%d, [%d]\n",temp_reg,var_loc->binding);
									fprintf(fp,"ADD R%d, R%d\n",p,temp_reg);
									freeReg();
									break;

							}				
	

							iter = iter->next;
							dim++;
						}

						system_call(fp,7,p,0);
						freeReg();
						break;

					/*	printf("inside read");
						struct varIndex *iter = t->left->arrayIndex;
						
						int loc = 0,t_reg,prevLoc=-1,const_flag = 0;
						loc = t->left->Gentry->binding;
						int dim = 1;
						while(iter!=NULL){
							

							if(iter->type == INTEGER_INDEX){
								loc += iter->index*dim_mul(dim,t->left->varname);
								const_flag =  1;
							}
							else{
								t_reg = getReg();
								int indexLoc = get_binding_addr(iter->name);
								

								fprintf(fp,"MOV R%d, [%d]\n",t_reg,indexLoc);
								fprintf(fp,"ADD R%d, loc\n");
								if(prevLoc!=-1){
									fprintf(fp, "ADD R%d, R%d\n",prevLoc,t_reg);
									freeReg();
								}
								else{
									prevLoc = t_reg;
								}
							}
							iter = iter->next;
							dim++;
						}
						if(prevLoc == -1){
							p = getReg();
							fprintf(fp,"MOV R%d, %d\n",p,loc);
							system_call(fp,7,p,0);
							freeReg();
						}
						else{
							if(!const_flag){
								system_call(fp,7,t_reg,0);	
								freeReg();
							}
						}

						break;*/

				case 'w' :	p = codeGenTree(t->left,fp);
						system_call(fp,5,p,0);
						break;


			
			}
			break; 
		case CONDITIONAL_EXP:
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
		case BREAK_EXP:
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
	temp->type = BREAK_EXP;
	switch(type){
		case BREAK_STATEMENT:
			temp->nodetype = 0;
			break;
		case CONTINUE_STATEMENT:
			temp->nodetype = 1;
			break;
	}
	return temp;
}

struct tnode* createTreeNode(int val, int type, char *c,int nodetype, struct tnode *l, struct tnode *r){
	
	struct tnode* temp = malloc(sizeof(struct tnode));

	switch(type){
		case NUMERIC_CONSTANT: //constants 
			temp->val = val;
			temp->type = type;
			temp->left = temp->right = NULL;
			break;
		case VARIABLE: //variables
			temp->val = 0;
			temp->type = type;
			temp->varname = malloc(sizeof(char)*strlen(c));
			struct Gentry *gIndex = lookup(c);
			
			if(gIndex==NULL&&block_no==0){
				printf("%s is not declared : line no %d\n",c);
				exit(-1);
			}
			
			temp->Gentry = gIndex;

			strcpy(temp->varname,c);
			temp->left = temp->right = NULL;
			break;
		case ARITHEMETIC_EXP: //arithemetic exp
			if(l->type==LOGICAL_EXP||r->type==LOGICAL_EXP){
				printf("type mismatch\n");
				exit(-1);
			}
			temp->val = 0;
			temp->type = type;
			temp->nodetype = nodetype;
			temp->left = l;
			temp->right = r;
			break;
		case EMPTY_NODE: //empty nodes
			temp->val = 0;
			temp->type = type;
			temp->nodetype = 'b';
			temp->left = l;
			temp->right = r;
			break;
		case LOGICAL_EXP:
			temp->type = type;
			temp->nodetype = nodetype;
			temp->left = l;
			temp->right = r;
			break;
			

		case READ_WRITE: //read and write
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

	if(l->type!=LOGICAL_EXP){
		printf("type mismatch\n");
		exit(-1);
	}

	temp->type = CONDITIONAL_EXP;

	switch(condition){
		case CIF:
			if(m->type==LOGICAL_EXP||r->type==LOGICAL_EXP){
				printf("Type mismatch for if\n");
				exit(-1);
			}
			temp->left = l;
			temp->middle = m;
			temp->right = r;
			temp->nodetype = 1;
			break;

		case CWHILE:
			if(r->type==LOGICAL_EXP){
				printf("Type mismatch for while\n");
				exit(-1);
			}
			temp->left = l;
			temp->right = r;
			temp->nodetype = 2;
			break;

		case CIF_ELSE:
			if(m->type==LOGICAL_EXP){
				printf("Type mismatch for if_else\n");
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
