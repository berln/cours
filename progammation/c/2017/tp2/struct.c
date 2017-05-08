#include <stdio.h>
#include <stdlib.h>
typedef struct S3 {
	char tab[3];
	char ** ctab;
}S3;

typedef struct S2 {
	int in;
	char tab[3];
	double dn;
	S3 * P;
}S2;

typedef struct S1 {
	char tab[3];
	int n;
	S2 * P;
}S1;






int main(int argc, char const *argv[])
{
	S2 * P2;
	S1 * P1;
	S3 * P3;

	P1=malloc(sizeof(S1));
	P2=malloc(sizeof(S2));
	P3=malloc(sizeof(S3));

	P1-> P=P2;
	P2-> P=P3;


	return 0;
}
