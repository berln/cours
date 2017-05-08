/************************/
/*ECRITURE DANS LE TUBE*/				
/************************/
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

void main(void)
{
   int fd , i , ret;

   char buff[50];

   for(i=0 ; i<50 ;i++)
      buff[i] = 'a';

   fd = open("/tmp/tubessai" , O_WRONLY);

   if(fd == -1)
   {
      perror("open");
      exit(1);
   }
   else
   {

      ret = write(fd , buff , 50);
      printf("\nretour du write : %d\n" , ret);

      if(ret == -1)
      {
        perror("write");
        exit(1);
      }
   }
close(fd);
}
