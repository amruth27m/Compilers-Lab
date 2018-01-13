#ifndef COMPILERLAB_H_   /* Include guard */
#define COMPILERLAB_H_

//Function to backup and restore registers to stack
void register_data_handle(int flag, FILE* opfile,int begin , int end );

//Function to print header to a XEXE executable
void write_header(FILE *opfile);

void system_call(FILE *fp, int syscallno,int data,int opreg,int reg_backup);

void pop_after_syscall(FILE* fp, short syscallno, short op_register);

#endif // FOO_H_
