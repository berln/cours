

/*----------------------------------------------------------------------------*/
/* Prog1ExeclProg2.c
/*----------------------------------------------------------------------------*/
/* ETUDE SIMPLE DE L'EXECL DANS LE PROCESSUS COURANT                           */
/* PROG2 SE SUBSTITUE AU PROGRAMME EN COURS SANS CREATION DE PROCESSUS         */
/*----------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void affiche(char *);

/*---------------------------------------------------------------------------*/
int main ()

{    affiche ("avant execl");
   
     /* le programme en cours est remplace par le code executable dU PROGRAMME */
     /*  PROG2 */
     /* si execl reussit, on ne revient pas dans le programme en cours        */
      
      execl ("./prog2","Prog2","Coucou",(char*)0);
      affiche ("Si je passe ici execl a echoue");
}	
/*--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void affiche (char *message)
{ printf ("\n %s pid=%d ppid=%d\n", message, getpid(), getppid());}
/*---------------------------------------------------------------------------*/
           