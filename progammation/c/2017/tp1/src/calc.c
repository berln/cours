#include <stdio.h>
#include <stdlib.h>
#include "mesTypes.h"

int  calc(int pOp1, char pOperateur, int pOp2){
	switch (pOperateur){
		case '+':
		return add(pOp1,pOp2);

		case '-':
		return minus(pOp1,pOp2);

		case '*':
		return mult(pOp1,pOp2);

		case '/':
		return divi(pOp1,pOp2);

		case '%':
		return mod(pOp1,pOp2);

		case '&':
		return ET(pOp1,pOp2);

		case 'E':
		return puiss(pOp1,pOp2);

		case '|':
		return OU(pOp1,pOp2);

		case '^':
		return OUEX(pOp1,pOp2);
	}
}