#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// ***********************************************************************
// * who | wc ds tube non nommé , 1 seul programme 2 taches (pere et fils)
// * who dans le fils ecrit ds tube[1) et wc dans le pere lit dans tube[0]
// ***********************************************************************
main()
{
  int pid;
  int tube[2];
// ****************************
// creation du tube non nomme
// ***************************
if (pipe (tube) == -1)
   { perror ("\n tube non cree \n");
     exit(1);
   }

pid = fork ();
if (pid == -1)
   { perror ("\n fils non cree \n");
     exit(2);
   }
if (pid > 0) 
   {
      /* Processus père      */
        printf("\npere\n");
        close(0);
        dup (tube[0]);
        close (tube[1]);
        close (tube[0]);
        execl("/usr/bin/wc", "wc", (char*) 0);
        printf ("\n execl wc refusé ");
   } 
   else 
   {
      /* Processus fils      */
        close(1);
        dup (tube[1]);
        close (tube[1]);
        close (tube[0]);
        execlp("/usr/bin/who", "who", (char*) 0);
        printf ("\n execl who refusé ");


   }
printf("\nfin\n");
}