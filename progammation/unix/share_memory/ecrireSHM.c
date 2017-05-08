#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
main(int argc, char **argv)
{
/*  argv[1] doit contenir l'identifiant de la SHM (code de retour du shmget du programme de création de la SHM) */
   int id, i;
char *pt, buffer[100];
   struct shmid_ds shm;
   id=atoi(argv[1]);
   printf("\necrire SHM\n");
   pt = (char *) shmat((key_t)id, 0, IPC_NOWAIT);
   if(id == -1)
   {
        perror("\nerreur shmat()\n");
        exit(1);
   }
       printf("\nsaisir le texte:\n");
        i=0;
        do{ scanf("%c", &buffer[i]);
            i++;
          }while(buffer[i-1]!='\n');
buffer[i-1]='\0';
strcpy(pt,buffer);
shmdt(pt);
}