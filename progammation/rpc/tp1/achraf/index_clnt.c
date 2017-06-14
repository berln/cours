#include "index.h"

struct ligne tab;
char ** nom;
int status_ajout;
struct liste list;


ligne * recherche_1 ( char ** nom ) {
	callrpc("localhost", NB_PROG, NB_VERS, PROC_RECH, xdr_wrapstring, nom, xdr_ligne, &tab);
	return(&tab);
}

int * ajout_1 ( ligne * a_ajouter ) {
	callrpc("localhost", NB_PROG, NB_VERS, PROC_ADD, xdr_ligne, a_ajouter, xdr_int, &status_ajout);
	return(&status_ajout);
}

liste * liste_1 () {
	callrpc("localhost", NB_PROG, NB_VERS, PROC_CHAINE, xdr_void, NULL, xdr_liste, &list);
	return(&list);
}
