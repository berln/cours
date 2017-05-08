#include <stdio.h>
int ordonner(double t[], int n){
	int i;
	double tmp=t[0];
	for (i = 1; i < n; ++i)
	{
		if (t>tmp)
		{
			return 0;
		}
		tmp=t[i];
	}
	return 1;
}