#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	fork();
	execlp("ls","ls",NULL);
	printf("lapin\n");
	return 0;
}
