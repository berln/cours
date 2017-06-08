/* 

   Gestion d'un index telephonique 
   (pour etre server RPC avec rpcgen)

   fichier donnee: lignes ascii de la forme "nom telephone(entier)" 

*/

#include "index.h"

#define NOM_FICHIER "index.data"

/* Recherche de la ligne contenant le nom correspondant... */

static ligne entree;
static char buf[256];

ligne * recherche_1 ( char ** nom ) {
  FILE *f;
  int t;

  entree.nom = (char *)buf; entree.tel = 0;
  if ((f = fopen (NOM_FICHIER, "r")) == NULL) {perror ("svc: fopen ");}
  else {
    while ( fscanf(f,"%s%d", buf, &t ) != EOF ) {
      if ( !strcmp( *nom, buf) ) {
	entree.tel = t;
	fclose ( f );
	return ( &entree );
      }
    }
    fclose ( f );
  } /* entry not found: return empty string */
  entree.nom[0] = '\0';
  return ( &entree );
}

/* Ajout d'une ligne si pas deja presente... */

static int status_ajout;

int * ajout_1 ( ligne * a_ajouter ) {
  FILE *f;
  ligne *test;

  status_ajout = 0;
  test = recherche_1 ( &(a_ajouter->nom) );
  if ( ! (test->tel) ) {
    f = fopen ( NOM_FICHIER, "a" );
    fprintf (f, "%s %d\n", a_ajouter->nom, a_ajouter->tel);
    fclose(f);
    status_ajout = 1;
  }
  return ( &status_ajout );
}

/* Affiche une chaine de caractere... */

void * affiche_1 ( char ** s ) {
  printf ( "%s\n", *s ); fflush (stdout);
  return ((void *)1);
}

/* liste les lignes */
liste * recherche_1 () {
  FILE *f;
  struct ligne tab;

/* A REECRIRE A PARTIR D'ICI */
  entree.nom = (char *)buf; entree.tel = 0;
  if ((f = fopen (NOM_FICHIER, "r")) == NULL) {perror ("svc: fopen ");}
  else {
    while ( fscanf(f,"%s%d", buf, &t ) != EOF ) {
      if ( !strcmp( *nom, buf) ) {
	entree.tel = t;
	fclose ( f );
	return ( &entree );
      }
    }
    fclose ( f );
  } /* entry not found: return empty string */
  entree.nom[0] = '\0';
  return ( &entree );
}

