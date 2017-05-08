#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*Trois programmes
1) Creation du tube nomme dans /tmp par mkfifo
2) Ecriture de 50 octets dans le tube nomme
3) Lecture des 50 octets dans le tube nomme*/

int main(int argc, char const *argv[]){
	int fd1,ret1;
	char buf1[]="bonjour";
	mkfifo ("/tmp/toto",0700);
	fd1=open("/tmp/toto",O_WRONLY);
	ret1=write(fd1,buf1,50);
	close(fd1);

/*Ouvrir un tube nommé en lecture et lire 8 caractères puis fermer le descripteur*/
	return 0;
}

