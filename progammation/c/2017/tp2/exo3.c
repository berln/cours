#include <stdio.h>
#include <stdlib.h>
typedef struct t_structL{
	int * tab;
	int n;
}t_structL;

void affichetab(int * itab , int n){
	for ( ; n -1 >=0; n--)
	{
		printf("%d\n",itab[n] );
	}
}

void delet_last(t_structL * P){
	P -> tab[P -> n -1]=0;
	P -> n--;
}

void insert(t_structL * P){
	int i;
	for (i = P-> n -1; i > 2 ; i--)
	{
		P-> tab[i+1]=P-> tab[i];
	}
	P-> tab [2]=88;
	P->n++;
}

int main(int argc, char const *argv[])
{
	t_structL * P;
	P=malloc(sizeof(t_structL));
	P -> tab=malloc(1000*sizeof(int));
	P -> tab [0]=3;
	P -> tab [1]=4;
	P -> tab [2]=5;
	P -> tab [3]=6;
	P -> tab [4]=7;
	P -> tab [5]=8;
	P -> n=6;
	delet_last(P);
	insert(P);
	affichetab(P -> tab,P -> n);

	return 0;
}

