#include "index.h"

struct ligne tab;
char ** nom;
int status_ajout;


ligne * recherche_1 ( char ** nom ) {
	callrpc("localhost", NB_PROG, NB_VERS, PROC_RECH, xdr_wrapstring, nom, xdr_ligne, &tab);
	return(&tab);
}

int * ajout_1 ( ligne * a_ajouter ) {
	callrpc("localhost", NB_PROG, NB_VERS, PROC_ADD, xdr_ligne, a_ajouter, xdr_int, &status_ajout);
	return(&status_ajout);
}
