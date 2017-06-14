#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "index.h"

/* filtre XDR pour la struct ligne */
bool_t xdr_ligne (XDR * flot, struct ligne * ptr){
	char ** nom = malloc(20 * sizeof(char));
	int tel;
	
	if (nom = NULL){
		printf("erreur malloc trop beaucoup !");
		exit(1);
	}
	
	return (xdr_string(flot, &ptr->nom, sizeof(nom)) && xdr_int(flot, &ptr->tel));
}
