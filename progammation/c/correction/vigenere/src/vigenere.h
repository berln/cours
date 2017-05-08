#ifndef _VIGENERE_H
#define _VIGENERE_H


#define BUFSIZE 10
#define ALPHMAXSIZE 255 
typedef enum {FALSE,TRUE} Bool;


int code(char * buf_mess, char * buf_key, char * alph, int size_alph,int op, Bool skip);
int find_char(char * alph, char x);
FILE* try_open_file(char * filename, char * prog_name, char * mode);
int fill_buff(FILE * f, char * buff, int size_b);
int last_slash(char * name);
char* basename(char * name);

#endif
