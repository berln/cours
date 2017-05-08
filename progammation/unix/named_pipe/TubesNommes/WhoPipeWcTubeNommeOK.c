
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
// *******************************************************************
// * who | wc ds tube nommé , 1 seul programme 2 taches (pere et fils)
// * who dans le fils et wc dans le pere
// *******************************************************************
main()
{
  int pid, fd, rtcmd;

   printf("\ntube nomme /tmp/toto cree\n");

// rtcmd=mknod("/tmpo/toto", S_IFIFO | S_IRWXU, O); identique au mkfifo
   rtcmd=mkfifo("/tmp/toto",0700);
   if(rtcmd==-1) perror("\n erreur mknod()\n");
   printf("\nfaire un \"rm /tmp/toto\"\n");

pid = fork ();
if (pid==-1) 
   { perror("\nerreur fork()\n");
     exit(0);
   }
if (pid > 0) 
   {  /* Processus pere      */
        printf("\npere pid: %d\n",getpid());
        close(0);

        printf("\n open en lecture\n");
        fd=open("/tmp/toto", O_RDONLY);
        if(fd==-1) 
          { perror("\nerreur open en lecture\n");
          exit(0);
          }
        printf("\n execl de wc\n");
        execl("/usr/bin/wc", "wc", NULL);
        printf ("\n execl wc refuse ");
        sleep(1);
        exit(0);

    } 
if (pid==0)
 { /* Processus fils      */
        printf("\nfils pid: %d\n",getpid());
        printf("\n open en ecriture\n");
        printf("\n execl de who\n");
// Apres le close(1), il ne faut plus faire de printf car il écrit ds 1
        close(1);
        fd=open("/tmp/toto", O_WRONLY);
        if(fd==-1) perror("\nerreur open en ecriture\n");

        
        execl("/usr/bin/who", "who", NULL);
        printf ("\n execl who refuse ");
  }
printf("\nfin\n");
}