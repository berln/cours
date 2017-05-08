#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <getopt.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <string.h>

#include "vigenere.h"

FILE* try_open_file(char * basename,char * prog_name,char* mode){

	FILE* f;
	char filename[100]; // longueur max de nom de fichier...
	int i,j;	

	strcpy(filename,prog_name);
	
	i=last_slash(filename);
	for(j=0;basename[j]!='\0';j++)
		filename[++i]=basename[j];
	filename[++i]='\0';	


	f=fopen(filename,mode);
	if(f==NULL){
		fprintf(stderr,"Error while trying to open file %s\n",filename);
		exit(1);
	}
	return f;
}


/*
   take two buffers of size BUZSIZE and the alphabet and encode the first one according to the key contained in the second one
   if op = 1 , decode is op = -1
*/
int code(char * buf_mess, char * buf_key, char * alph, int size_alph,int op, Bool skip)
{

	int i,j;

	// the second indice j is used to shift position when -s is asked
	for(i=0,j=0 ; buf_mess[i] != '\0' && i < BUFSIZE ; i++,j++){
		int code_m, code_k, sum;
		code_m = find_char(alph,buf_mess[i]);
		if(code_m==-1){
			if(skip )j--;
			continue; /* the letter is not in the alphabet */
		}
		code_k = find_char(alph,buf_key[j]);
		if(code_k==-1){
			fprintf(stderr,"the key contains a caracter which is not in the alphabet : %c\n",buf_key[j]);
			exit(1);
		}


		sum = code_k*op + code_m ;
		if(sum>=0)sum=sum%size_alph;
		else sum = size_alph + sum;

		buf_mess[j] = alph[sum];  
	}
	if(j<BUFSIZE)
		buf_mess[j]='\0';
	return j;

}

int find_char(char * alph, char x)
{
	int i;
	for(i=0; alph[i]!='\0' ; i++)
		if(x==alph[i])return i;
	return -1;
}


void print_help(char * prog_name){

/*
utilisation des appels systeme open et write pour vous montrer qu'on est pas oblige de passer par la libc (fopen/fclose/fread/fwrite/fgets/...)
*/

	int i, fd;
	ssize_t byte_read;
	char buffer[BUFSIZE];
	char * basename = "../help.txt";
	char filename[100];
	strcpy(filename,prog_name);
	
	i=last_slash(filename);
	if(i!=-1){
		for(fd=0;basename[fd]!='\0';fd++)
			filename[++i]=basename[fd];
		filename[++i]='\0';	
	}

	fd = open(filename,O_RDONLY);



	if (fd == -1){
		perror("open: ");
		exit(1);
	}
	while((byte_read=read(fd,buffer, BUFSIZE))){ 
		if(byte_read==-1){
			perror("open: ");
			exit(1);
		}
		write(STDOUT_FILENO, buffer, byte_read);
	}

	close(fd);

}


int fill_buff(FILE * f, char * buff, int size_b){

	size_t ret_val;

	if(f==stdin)
		{
			// on ne peut pas utiliser fread car l'appel est bloquant si on rentre moins de size_b caractere...
			fgets(buff,size_b,f);
			return strlen(buff);
		}


	ret_val = fread(buff, sizeof(char), size_b, f);
	
	
	

	if(ferror(f)){
		fprintf(stderr,"error reading a file\n");
		exit(1);
	}


	return ret_val;	

}


/**
BUG si on passe un nom de fichier se terminant par / mais n'est utiliser qu'avec arv[0], donc ce n'est pas un probleme 
**/
int last_slash(char * name){

	int i;
	int last_slash_index=-1;
	for(i=0; name[i] !='\0';i++)
		if(name[i]=='\\' || name[i]=='/')
			last_slash_index=i;
	return last_slash_index;

}

char* basename(char * name){

	int i;
	int last_slash_index= last_slash(name);
	if (last_slash_index==-1)return name;
	return name+last_slash_index+1;

}



int main(int argc, char** argv){


	char * k_filename = "../default_files/key.txt";
	char * a_filename = "../default_files/alphabet.txt";
	FILE * in = stdin;
	FILE * out = stdout;	
	FILE * k_file=NULL;
	FILE * a_file=NULL;
	Bool skip = FALSE;
	int size_alph;

	int op = strcmp("code",basename(argv[0]))==0 ? 1 : -1;

	char buf_mess[BUFSIZE];
	char buf_key[BUFSIZE];
	char alph[ALPHMAXSIZE+1]; /* +1 pour marquer le \0 */




	/*
 gestion des options 
	 */
	while (1) {
		int c;
		static struct option long_options[] =
		{
			{"help", no_argument, NULL, 'h'},
			{"skip", no_argument, NULL, 's'},
			{"key",  required_argument, NULL, 'k'},
			{"alphabet",  required_argument, NULL, 'a'},
			{0, 0, 0, 0}
		};

		c = getopt_long(argc, argv, "hsk:a:",
				long_options, NULL);
		if (c == -1)
			break;

		switch (c) {
			case 'h':
				print_help(argv[0]);
				exit(0);

			case 's' :
				skip = TRUE;
				break;
				
			case 'k' :
				k_filename = optarg;
				k_file=try_open_file(k_filename,"","r");
				break;
			
			case 'a' :
				a_filename = optarg;
				a_file=try_open_file(a_filename,"","r");
				break;
			
	
			default:
				fprintf(stderr,"invalid option, getopt returns caracter code 0%o\n",c);
				print_help(argv[0]);
				exit(1);

		}
	}

	if(k_file==NULL)
		k_file=try_open_file(k_filename,argv[0],"r");
	if(a_file==NULL)
		a_file=try_open_file(a_filename,argv[0],"r");

	if (optind == argc-1) 
		in = try_open_file(argv[optind],"","r");
	else if (optind == argc-2){
		in = try_open_file(argv[optind],"","r");	
		out = try_open_file(argv[optind+1],"","w");	
	} else if (optind<argc){
		fprintf(stderr,"too many arguments\n");
		print_help(argv[0]);
		exit(1);
	}
	

	/* lit l'alphabet -- si > 255 tronque, pas de message d'erreur TODO */
	size_alph=fill_buff(a_file,alph, ALPHMAXSIZE);
	if(alph[size_alph-1]=='\n')size_alph--;
	alph[size_alph]='\0';


	while(1)
	{
		int nb_read,nb_rk, nb_code;
		nb_read=fill_buff(in,buf_mess,BUFSIZE-1);

		if(buf_mess[nb_read-1]=='\n')nb_read--;

		if(nb_read==0)
			break;

		

		buf_mess[nb_read]='\0';

		nb_rk=fill_buff(k_file,buf_key,nb_read);
		if(buf_key[nb_rk-1]=='\n')nb_rk--;
		while(nb_rk<nb_read){
			int tmp;
			rewind(k_file);
			tmp=fill_buff(k_file,buf_key+nb_rk,nb_read-nb_rk);	
			if(buf_key[tmp-1]=='\n')tmp--;
			nb_rk+=tmp;
		}
		buf_key[nb_read]='\0';

		nb_code = code(buf_mess,buf_key,alph,size_alph ,op, skip);
		if(nb_code<nb_read)
			fseek(k_file,nb_code-nb_read,SEEK_CUR);		

		fputs(buf_mess,out);

	}


	if(in!=stdin)fclose(in);
	if(out!=stdout)fclose(out);
	fclose(k_file);
	fclose(a_file);

	return 0;

}

