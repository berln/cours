#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int main()
{  int pid, pidf, status;
   printf("\n pere de pid: %d\n",getpid());

//---------------------------------------------------------------
// Créer un fils qui exécute une boucle infinie (while (1)   
   pidf=fork();
   if(pidf==-1)
         {  printf("\n erreur fork()  A \n");
            exit(0);
         }
   if(pidf==0)
         { /* processus fils */
             printf("\nfils cree de pid: %d \n",getpid());
             while(1);
         }
// BRANCHE DU PERE
   sleep(1);

// --------------------------------------------------------------
// VISUALISATION (PAR PS) DU FILS CREE
   pid=fork();
   if(pid==-1)
            {/* erreur */
             printf("\n erreur fork() B :\n");
             exit(1);
            }
    if(pid==0)
           {/* processus fils */
            printf("\n VISUALISATION PAR PS DE LA CREATION DU FILS \n");
            printf("\n fils de pid: %d pour ps\n", getpid());
            execl("/bin/ps", "ps","-l" ,(char*)0);
            printf (" \n si on passe ici execl A a echoue \n");
            exit (10);
           }
// branche du pere   
   sleep(1);
   printf ("\n TUER LE FILS DE PID %d \n", pidf);

//------------------------------------------------------------------
// TUER LE FILS 
          printf("\n SIGKILL DU FILS \n", pidf);
          kill(pidf, SIGKILL);

// OBSERVER PAR PS LE PASSAGE DU FILS A L ETAT ZOMBIE  
   pid=fork();
   if(pid==-1)
            {/* erreur */
             printf("\n erreur fork() C :\n");
             exit(2);
            }
   if(pid==0)
           {/* processus fils */
            printf("\n fils de pid: %d pour ps\n", getpid());
            execl("/bin/ps", "ps","-l", (char*)0);
            printf (" \n si on passe ici execl B a echoue \n");
            exit (10);
           }
// BRANCHE DU PERE QUI DOIT MOURIR APRES SON FILS SINON LE ZOMBIE DISPARAITRA 
// AVANT LE PS QUI DOIT LE VISUALISER
   sleep(2);
}

