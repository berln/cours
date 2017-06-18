#include "index.h"

/* code serveur */
main (int argc, char * argv[]){
	char ** nom;
	struct ligne tab;
	
	registerrpc(NB_PROG,NB_VERS,PROC_RECH,recherche_1,xdr_wrapstring,xdr_ligne);
	registerrpc(NB_PROG,NB_VERS,PROC_ADD,ajout_1,xdr_ligne,xdr_int);
	registerrpc(NB_PROG,NB_VERS,PROC_CHAINE,liste_1,NULL,xdr_liste);
	
	svc_run();
}
