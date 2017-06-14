#include <xdr.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <rpc/xdr.h>

struct ligne {
	char *nom;
	int tel;
};

typedef struct ligne ligne;

extern void * affiche_1();

extern ligne *recherche_1();

extern int *ajout_1();
