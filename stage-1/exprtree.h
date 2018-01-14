#ifndef EXPTREE_H_
#define EXPTREE_H_
#define reg_index int
#define WRITE 5
#define READ 7
#define EXIT 10

typedef struct tnode{
	int val;
	char *op;
	struct tnode *left, *right;
}tnode;

struct sys_call_abi{
        int sys_call_number,arg1,arg2,arg3,interrupt_no;
        char sys_call_name[10];
};


struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c,struct tnode *l, struct tnode *r);
int evaluate(struct tnode *t);
void print_tree(FILE *fp, struct tnode *t,int type);
void write_header(FILE* fp);
reg_index codeGenTree(struct tnode *t, FILE* fp);
void register_data_handle(int flag, FILE* opfile,int begin , int end );
void system_call(FILE *fp, int syscallno,int arg2,int opreg,int reg_backup );


#endif
