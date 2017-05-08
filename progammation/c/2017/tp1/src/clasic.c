#include "mesTypes.h"
#include <stdio.h>
#include <stdlib.h>

int add(int ia,int ib){
	return(ia+ib);
}

int minus (int ia,int ib){
	return(ia-ib);
}

int mult(int ia,int ib){
	return(ia*ib);
}

int divi (int ia,int ib){
	if(ib!=0)
		return(ia/ib);
}
