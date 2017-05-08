#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
int main(){
    char *fichier="toto";
    int coderr;
    coderr=creat(fichier,0600);
    if(coderr==-1){

        perror("\nErreur :\n");
        exit(1);
    }


    return 0;
}
