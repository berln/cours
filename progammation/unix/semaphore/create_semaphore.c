#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
#define CLE 101

int main(int argc, char const *argv[])
{
	int id;
	id = semget(IPC_PRIVATE,1,0666); /*1 represente le nombre de semaphore, 0666 represente les droits d'acces*/
	semctl(id,0,SETVAL,2);
	/*semctl(id,0,SETVAL,X) X represente le nombre d'acces possible*/
	printf("%d\n",semctl(id,0,GETVAL) );
	printf("%d\n",id );


	return 0;
}