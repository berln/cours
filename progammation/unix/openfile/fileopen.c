#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	char * file_name = "toto";
	int fd1;
	/*fd2=open(file_name, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);*/
	if(fd1=creat(file_name,0600)!=0){
		perror("canotcreate file");
		exit(1);
	}
	return 0;
}