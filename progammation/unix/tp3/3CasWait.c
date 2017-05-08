#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
main()
{  int status;
   int rep;
   int retour;
   printf("\npid pere  %d \n",getpid());

// PREMIER FORK
   rep = fork();
   if(rep == -1)
	{ perror("\nerreur fork1\n");
		exit(0);
	}
   if(rep > 0)	
// PERE APRES PREMIER FORK
     // DEUXIEME FORK
        {
    	rep = fork();
	if(rep == -1)
	{ perror("\nerreur fork2\n");
	  exit(0);
	}

	if(rep > 0)
// PERE APRES DEUXIEME FORK
	{      sleep(15);
	      // recupere le testament du 1er fils zombie (le 2eme fils est vivant)
                retour = wait(&status);
		printf("\ncode retour 1er wait : %d status %x et pid pere: %d \n",retour, status, getpid());
		sleep(1);
	      // attend la mort du 2ieme fils vivant pour recuperer son testament (il n y a plus de zombie)		
                retour = wait(&status);
		printf("\ncode retour 2eme wait : %d status %x et pid pere : %d \n",retour, status, getpid());
		sleep(2);
              // il n y a plus de fils (ni vivant ni zombie)			
                retour = wait(&status);
		
		printf("\ncode retour 3eime wait : %d et pid : %d \n",retour, getpid());
		exit(0); //mort du pere
	}
	else
//DEUXIEME FILS	
        {       printf("\ndeuxieme fils : %d \n", getpid());
		sleep(20);
		exit(2);
	}        
    }
    else
	{
// PREMIER FILS
		sleep(1);
		printf("\npremier fils : %d \n", getpid());
		exit(1);
	}
}