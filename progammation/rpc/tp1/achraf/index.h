
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <rpc/types.h>
#include <rpc/xdr.h>

#define NB_PROG 0x22222222
#define NB_VERS 1
#define PROC_RECH 1
#define PROC_ADD 2
#define PROC_CHAINE 3

struct ligne {
	char *nom;
	int tel;
};

struct liste {
	struct ligne tab;
	struct liste * next;
};

typedef struct ligne ligne;
typedef struct liste liste;

extern void * affiche_1();

extern ligne *recherche_1();

extern int * ajout_1();

extern liste * liste_1();

extern bool_t xdr_ligne();
extern bool_t xdr_liste();
