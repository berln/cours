/*======================= LANCE ==================================*/
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int ret;

/*======================================================*/
/* $lance Nom_Programme_a_lancer Temps_limite_execution */
/* Le programme à lancer ne contient que sleep(10)      */
/*======================================================*/

void tuer ()
{ 
  signal(SIGCHLD,SIG_IGN);
  kill(ret,SIGKILL);
  printf("\n assassinat du fils \n");
  exit(1);
}

void ok ()
{  signal(SIGALRM,SIG_IGN);
   printf("\n mort naturelle du fils\n");
  exit(2);
}

int main(int argc,char **argv)
{ int nb;
  signal(SIGALRM,tuer);
  signal(SIGCHLD,ok);
  nb=atoi(argv[2]);
  alarm(nb);
  ret=fork();
  if (ret == -1)
     { perror ("\n fork refuse \n");
       exit(0);
     }
  if (ret == 0)
     { execl(argv[1],argv[1],(char *)0);
       printf ("\n refus execl \n");
     }
  if (ret>0)  sleep (nb + 1);
}

