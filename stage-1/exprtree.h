#ifndef EXPTREE_H_
#define EXPTREE_H_
#define reg_index int
typedef struct tnode{
	int val;
	char *op;
	struct tnode *left, *right;
}tnode;

struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c,struct tnode *l, struct tnode *r);
int evaluate(struct tnode *t);
void print_tree(FILE *fp, struct tnode *t,int type);
void write_header(FILE* fp);
reg_index codeGenTree(struct tnode *t, FILE* fp);

#endif
