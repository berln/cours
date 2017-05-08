/*------------------------------------------------------------------------*/
/* ForkExeclPs.c
/*------------------------------------------------------------------------*/
/* ETUDE SIMPLE DE L'EXECL DANS LA BRANCHE DU FILS                                                 */
/* LA COMMANDE PS SE SUBSTITUE AU PROGRAMME EN COURS DS LE PROCESSUS FILS */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void affiche(char *);

/*----------------------------------------------------------------------------*/
int main ()

{  int retour;
   affiche ("avant fork");
 
   retour=fork();
   if (retour==-1) /* fils non cree */
 	  exit(0); /* arret du programme par suicide du processus */
 
    
/* Partie de programme executee par le pere (cas ou le fils est cree*/ 
    if (retour >0)
    {   sleep (1); /* endormir le pere pendant une seconde       */
                   /* pour laisser le fils mourir avant son pere */
  	affiche ("Branche pere");
    }
    else

/* Partie de programme executee par le fils */
     /* le programme en cours est remplace par le code executable de ps */
     /* si execl reussit, on ne revient pas dans le programme en cours        */
   
 	{ affiche ("debut de la branche fils");
          execl ("/bin/ps","ps","-l",(char*)0);
   	  affiche ("Si je passe ici execl a echoue");
        }	
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void affiche (char *message)
{ printf ("\n %s pid=%d ppid=%d\n", message, getpid(), getppid());}
/*----------------------------------------------------------------------------*/