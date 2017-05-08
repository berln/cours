#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int pida, pidb, status, retour;

	pida=fork();
	if (pida==1)
	{
		printf("error fork\n");
	}
	if (pida==0){
		printf("fork cree pid @ %d\n",getpid() );
		sleep(1);
		exit(1);
	}

	pidb=fork();
	if (pidb==1)
		printf("error fork\n");
	if (pidb==0){
		printf("fork cree pid @ %d\n",getpid() );
		sleep(20);
		return(9);
	}

	sleep(15);
	retour = wait(&status);
	printf("\nreturn 1er wait : %d status %x pid pere: %d \n",retour, status, getpid());
	sleep(1);
	retour = wait(&status);
	printf("\nreturn 2nd wait pid= %d status %x pid pere: %d \n",retour, status, getpid());

	retour = wait(&status);
	printf("\nreturn 2nd wait pid= %d status %x pid pere: %d \n",retour, status, getpid());
	execl("/bin/ps", "ps","-l" ,(char*)0);
	return 0;
}