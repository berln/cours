#include <stdio.h>
double somme (double t[],int n){
	double result=0;
	int i;
	for ( i = 0; i < n; ++i)
	{
		result=result+t[i]
	}
	return result;
}

double moyenne(double t[],int n){
	int result;
	return (somme(t,n)/n);	

}