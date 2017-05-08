#include <stdio.h>

int indice_premier_negatif (double t[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		if (t[i]<0)
		{
			return i;
		}
	}
	return -1;
}

double valeur_plus_grande(double t[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		if (t[i]>0)
		{
			return t[i];
		}
	}
	return -1;
}

int valeur_plus_grande(double t[], int n){
	int i;
	for (i = 0; i < n; ++i)
	{
		/* code */
		if (t[i]>0)
		{
			return i;
		}
	}
	return -1;
}