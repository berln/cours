#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd2,ret2;
	char buf2[50];
	close(0);
	open("/tmp/toto",O_RDONLY);
	execl("/usr/bin/wc","wc",NULL);
	close(fd2);
	return 0;
}