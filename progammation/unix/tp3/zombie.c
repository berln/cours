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
	}

	pidb=fork();
	if (pidb==1)
		printf("error fork\n");
	if (pidb==0){
		printf("fork cree pid @ %d\n",getpid() );
		sleep(2);
	}
	sleep(5);
	execl("/bin/ps", "ps","-l" ,(char*)0);
}