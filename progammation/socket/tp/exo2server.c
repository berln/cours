#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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
	struct sockaddr_in adr,adr_rx;
	int slen = sizeof(si_other) , recv_len;
	s=socket (AF_INET,SOCK_stream,0);
	if(s==-1)
  		printf("prob");

	adr.sin_family=AF_INET;
	adr.sin_port=htons(atoi(argv[1]));
	adr.sin_addr.s_addr=INADDR_ANY;

	if(bind(s,(struct sockaddr *) &adr, sizeof(adr))== -1)
		printf("error bind\n");
	if(listen(s,5)==-1)
		perror("lol");

	sizeaddr=sizeof(adr);

	recvfrom(s,&msg,sizeof(msg),0,(struct sockaddr*)&adr,&slen);
	//sendto(s2,&msg,sizeof(msg),,&ad_dest,sizeof(ad.dest));

		return 0;
	}