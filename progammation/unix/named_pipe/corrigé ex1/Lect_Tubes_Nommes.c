/************************/
/*LECTURE DANS LE TUBE  */				
/************************/
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main(void)
{
   int fd , i , ret;
   char buff[50];

   fd = open("/tmp/tubessai" , O_RDONLY);

   if(fd == -1)
   {
      perror("\nopen\n");
      exit(1);
   }

   else
   {
           ret = read(fd , buff, 50);
           printf("\ncode de retour du read : %d\n" , ret);

           if(ret == -1)
           {
            perror("\nread : \n");
            exit(1);
           }
           else
           {
                printf("\n");

                for(i=0 ; i<50 ; i++)
                        printf("%c" , buff[i]);

           }    printf("\nFin de lecture\n");
   }
close(fd);
}
