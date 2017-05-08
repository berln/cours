#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
int main(){
    int fd1;
    char buf[20];
    long rtcmd;

    int i;
    printf("\nPid : %d\n",getpid());
    for (i=5;i<20;i++)
        signal(i,func1);

    while(1);

    fd1=open("toto",O_RDONLY);
    rtcmd=read(fd1, buf, 20);
    buf[20]='\0';
    printf("%s",buf);
    return 0;
}
