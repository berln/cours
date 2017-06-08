
/* 
   gestion d'index telephonique (pour etre Client RPC)
          L. Perroton - ESIEE - 2015
*/

#include "index.h"

menu(){
  printf ( "\n       Menu:\n");
  printf ( "1) Rechercher un nom\n");
  printf ( "2) Ajouter un nom\n");
  printf ( "3) Faire afficher au srv\n");
  printf ( "4) lister les noms\n");
  printf ( "5) Terminer le serveur\n");
  printf ( "6) Recherche avec callback\n");
  printf ( "7) Connecter a un autre srv \n");
  printf ( "8) Quiter\n\n");
  printf ( "Faites votre choix + Enter: ");
}

main (int argc, char ** argv) {
  char *chaine = (char *)malloc(256), telephone[256];
  ligne *resultat, nouvelle;
  liste *retour;
  
  menu();
  while (  scanf("%255s", chaine) ) {
    switch ( chaine[0] ) {
    case '1': /* recherche une entree dans l'index */
      printf ( "Recherche nom : ");  scanf("%255s", chaine);
      resultat = recherche_1 ( &chaine );
      printf ( "Nom : %s \t tel : %d\n", resultat -> nom, resultat -> tel );
      break;
    case '2': /* ajoute une entree  */
      printf ( "Ajout Nom : ");  scanf("%255s", chaine); nouvelle.nom = chaine;
      printf ("Tel : "); scanf ("%d", &nouvelle.tel ); getchar();
      printf ("Ajout: %d \n", *(ajout_1( &nouvelle )) );
      break;
    case '3': /* affiche... */
      printf ( "Afficher : ");  scanf("%255s", chaine);
      printf ("%s\n", chaine);
      break;
    case '4': /* liste chainee */
      printf("\nListe : \n\n");
      retour = liste_1();
      while (retour !=NULL) {
      		printf("%s %d\n", retour->tab.nom, retour->tab.tel);
      		retour = retour->next;
      }
    case '8': /* quitter le client */
      exit(0);
      break;
    default: 
      printf ("Option non (encore) implémenté...");
    }
    menu();
  }

}
