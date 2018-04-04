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
#define NUMERIC_CONSTANT 0
#define VARIABLE 1
#define ARITHEMETIC_EXP 2
#define EMPTY_NODE 3
#define LOGICAL_EXP 4
#define READ_WRITE 5
#define CONDITIONAL_EXP 6
#define BREAK_EXP 7
#define BREAK_STATEMENT 0
#define CONTINUE_STATEMENT 1
#define POINTER_ASSIGNMENT 8
#define INTEGER_INDEX 0
#define VARIABLE_INDEX 1
#define TYPE_INTEGER 0
#define TYPE_STRING 1
#define TYPE_POINTER 9

typedef struct tnode{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left, *right,*middle;
	struct Gsymbol *Gentry;			
	struct Lsymbol *Lentry;
	struct varIndex *arrayIndex;
	struct Paramstruct *param;
	struct typeVarList *typeList;
}tnode;

struct Gsymbol{
	char* varname;
	int type;
	int size;
	int binding;
	struct Gsymbol *next;			//pointer to the next global symobol table entry
	struct varIndex *shape;
	int flabel;				//label for identifying starting address of a functions code
	struct Paramstruct *paramlist;		//pointer to head of the formal parameter list in case of functions
}Gsymbol;

struct Paramstruct{
	char *name;
	int type;
	struct Paramstruct *next;
};

struct Lsymbol{
	char *varname;
	int type;
	int size;
	int binding;
	struct Lsymbol *next;
};



struct varList{
	char *name;
	int type;
	struct varIndex *index;
	struct varList *next;
	struct Paramstruct *paramlist;
};

struct typeVarList{
	int type;
	struct varList *vars;
	struct typeVarList *next;
};

struct varIndex{
	char *name;
	int index;
	int type;
	struct varIndex *next;
};

typedef int reg_index;
typedef int label_index;
typedef int f_label_index;
int break_stack[100];
int continue_stack[100];
int break_top,continue_top;
int binding_addr;

struct sys_call_abi{
        int sys_call_number,arg1,arg2,arg3,interrupt_no;
        char sys_call_name[10];
};

//returns pointer to symbol table entry else returns null
struct Gsymbol *lookup(char *name);

void initVariable(char *name, int type,struct varIndex* shape);


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
