#include<stdio.h>
#include<string.h>
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

struct tnode* makeLeafNode(int n){
	struct tnode* temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode* r){
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

void codeGen(struct tnode *t,FILE* fp){
	write_header(fp);
	codeGenTree(t,fp);
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
