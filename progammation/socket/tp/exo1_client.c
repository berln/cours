//client_serveur
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
/*struct sockaddr_in{
	short sin_family;
	u_short sint_port;
	struct in_addr sin_addr;
	char sin_zero[8];
}

struct in_addr{
	u_long s_addr;
} */

struct message{
	int pid;
	char * string;
};


int main(int argc, char const *argv[])
{
	/* code */
	int sizeaddr;
	struct message msg;
	int s;
	struct sockaddr_in adr;
	struct hostent *hp;

	msg.pid=getpid();
	msg.string="lol";

	hp=gethostbyname(argv[2]);
	memcpy( &adr.sin_addr.s_addr, hp -> h_addr, hp -> h_length);




	s=socket (AF_INET,SOCK_DGRAM,0);
	if(s==-1)
  		printf("prob");

	adr.sin_family=AF_INET;
	adr.sin_port=htons(atoi(argv[1]));
	adr.sin_addr.s_addr=INADDR_ANY;
	bind(s,(struct sockaddr *) &adr, sizeof(adr));

	sizeaddr=sizeof(adr);

	//recvfrom(s,&msg,sizeof(msg),0,(struct sockaddr*)&adr,(socklen_t*)&sizeaddr);
	sendto(s,&msg,sizeof(msg),0,(struct sockaddr*)&adr,sizeaddr);
	printf("%d\n",getpid() );

		return 0;
	}
