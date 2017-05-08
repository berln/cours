#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{

int pipeone[2];
pipe(pipeone);
char buffer[2048];

if (fork() == 0)
{
    close(pipeone[0]);    // ferme la lecture de l'enfant

    dup2(pipeone[1], 1);  // envoi stdout vers le pipe
    dup2(pipeone[1], 2);  

    close(pipeone[1]);

    mystere();
}
else
{
    // parent

    close(pipeone[1]);  // ferme l'ecriture pipe du pere

    printf("voila ce que j'ai lue\n");
    while (read(pipeone[0], buffer, sizeof(buffer)) != 0){
    printf("%s",buffer );
}
    printf("\n taille= %d\n",strlen(buffer) );
}
    /* code */
    return 0;
}