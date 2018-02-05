#ifndef EXPTREE_H_
#define EXPTREE_H_
#define WRITE_SYSCALL 5
#define READ_SYSCALL 7
#define EXIT_SYSCALL 10
#define CLT 9001
#define CLTE 9002
#define CGT 9003
#define CGTE 9004
#define CEQ 9005
#define CNEQ 9006
#define CIF 9007
#define CWHILE 9008
#define CIF_ELSE 9009
typedef struct tnode{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left, *right,*middle;
}tnode;


typedef int reg_index;
typedef int label_index;

int break_stack[100];
int continue_stack[100];
int break_top,continue_top;

struct sys_call_abi{
        int sys_call_number,arg1,arg2,arg3,interrupt_no;
        char sys_call_name[10];
};


struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c,struct tnode *l, struct tnode *r);
struct tnode* createTreeNode(int val, int type, char* c, int nodetype, struct tnode *l, struct tnode *r);

int evaluate(struct tnode *t);
void print_tree(FILE *fp, struct tnode *t,int type);
void write_header(FILE* fp);
reg_index codeGenTree(struct tnode *t, FILE* fp);
void register_data_handle(int flag, FILE* opfile,int begin , int end );
void system_call(FILE *fp, int syscallno,int arg2,int opreg);


#endif
