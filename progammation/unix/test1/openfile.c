#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char file_name = {toto};
	int fd2;
	fd2=open(file_name, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	return 0;
}