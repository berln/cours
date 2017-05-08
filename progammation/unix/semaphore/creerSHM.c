#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <errno.h>
#define CLE 101
main()
{
	int id;
	struct shmid_ds shm;
	printf("\ncreer SHM\n");
	id = shmget((key_t)CLE, 100, IPC_CREAT|0700);
	if(id == -1){
	     perror("\nerreur shmget()\n");
	     exit(0);
             }
	printf("\nSHM cree shmid : %d\n",id);
	printf("%d\n",id );
/* ne pas confondre CLE qui est un paramètre utilisateur et id qui sera nécessaire dans  */
/* les programmes lire et ecrire */

}