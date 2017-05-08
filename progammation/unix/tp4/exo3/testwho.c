#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	execl("./mystere.o","mystere.o",NULL);
	return 0;
}