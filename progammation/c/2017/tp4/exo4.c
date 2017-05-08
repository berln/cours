#include <stdio.h>
#include  <stdlib.h>

typedef struct auteur{
	char prenom [10];
	char name [15];
	int  numero;
	int  nombre_oe;
	float  popu;
} typeauteur;
/*
void write_file(){
	FILE *fp;
	char str[] = "This is tutorialspoint.com";

   fp = fopen( "auteurs.txt" , "wb" );
   fwrite(&str , 1 , sizeof(str) , fp );

   fclose(fp);
}*/

void write_file(char * filename){
	FILE *fptr;
	typeauteur test;
	if((fptr = fopen("auteurs.txt","w"))==NULL)
 	 {
 	 printf("nError in Opening File");
	  exit(0);
 	 } 
	printf("enter name : ");
 	 scanf("%s",test.name);
 	 printf("enter firstname : ");
 	 scanf("%s",test.prenom);
 	 printf("enter number : ");
 	 scanf("%d",&test.numero);
 	 printf("enter number of book : ");
 	 scanf("%d",&test.nombre_oe);
 	 printf("enter popularity in number : ");
 	 scanf("%f",&test.popu);
  	fwrite(&test,sizeof(typeauteur),1,fptr);
  	fclose(fptr);
  }

void open_file(char * filename,int ofset){
	typeauteur test;
	FILE *fptr;
	if((fptr = fopen("auteurs.txt","rb"))==NULL){
		printf("\nError in Opening File");
		exit(0);
	} 

	fwrite(&test + (


		f(typeauteur)),sizeof(typeauteur),1,fptr);
		printf("\nName : %s",test.name);
		printf("\nprenom : %s",test.prenom);
		printf("number %d\n",test.numero);
		printf("number of book%d\n",test.nombre_oe);
		printf("number popularity%f\n",test.popu);
	
	fclose(fptr);
	if(ofset==0)
		exit(0);
	open_file(filename,ofset -1);
}

int main(int argc, char const *argv[])
{
	char * filename="auteur.txt";
	write_file(filename);
	open_file(filename,5);
	return 0;
}