#include<stdio.h>
#include "exprtree.h"

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
