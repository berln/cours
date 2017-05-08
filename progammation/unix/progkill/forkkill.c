#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int rep;
	// PREMIER FORK
   rep = fork();
   if(rep == -1)
	{ perror("\nerreur fork1\n");
		exit(0);
	}
   if(rep > 0){
   		execl("./prog.o");
   }
	/* code */
	return 0;
}