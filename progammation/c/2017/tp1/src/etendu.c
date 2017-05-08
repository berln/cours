#include "mesTypes.h"
#include <stdio.h>
#include <stdlib.h>

int mod(int pa, int pb){
	return(pa%pb);
}

int puiss (int px, int pn){
	int res=1;
	if (pn>=0)
	{
		for ( pn; pn > 0; pn --)
		{
		res=res*px;
		}
	}
	return res;
}

int somCarre(int pa,int pb){
	return((pa*pa)+(pb*pb));
}

