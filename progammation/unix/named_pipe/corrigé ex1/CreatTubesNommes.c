/************************/
/*CREATION DU TUBE NOMME*/				
/************************/
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(void)
{
    int ret;
// /tmp est un repertoire dans lequel tous les users peuvent creer un tube nomme
// detruire le tube par rm /tmp/tubessai avant de recreer un tube
// mkfifo de la ligne suivante est equivalent de 
// mknod("/tmp/tubessai",S_IFIFO | S_IRWXU,0)
    ret = mkfifo("/tmp/tubessai" , 0700);
    if(ret==-1)
                perror("mkfifo:");
}