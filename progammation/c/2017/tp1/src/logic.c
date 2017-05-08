#include "mesTypes.h"
#include <stdio.h>
#include <stdlib.h>
int OU(int pa, int pb){
	return pa||pb;
}

int ET(int pa, int pb){
	if (pa==0 | pb == 0)
	{
		return 0;
	}
	return 1;
}

 int  OUEX (int pa, int pb){
 	if(pa!=pb)
 		return 1;
 	return 0;
 }
