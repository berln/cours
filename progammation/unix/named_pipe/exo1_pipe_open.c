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
	fd2=open("/tmp/toto",O_RDONLY);
	ret2=read(fd2,buf2,8);
	printf("%s\n",buf2);
	close(fd2);
	return 0;
}
