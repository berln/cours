#include <stdio.h>

void affiche_tab(double t[],int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		printf("%f\n",t[i] );
	}
}

double init(double t[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		t[i]=0
	}
}