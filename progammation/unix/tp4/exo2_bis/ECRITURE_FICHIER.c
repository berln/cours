#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd1;
    int coderr;
    char buf[20];

    fd1=open("toto",O_WRONLY);
    if(fd1==-1)
    {
        perror("\nErreur fd1:\n");
        exit(1);
    }
    gets(buf);

    write(fd1,buf,strlen(buf));
    fd1=open("toto",O_RDONLY);


    buf[20]='\0';

    return 0;
}

