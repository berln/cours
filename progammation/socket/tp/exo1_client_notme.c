struct _msg {
int pid;
char message[255];
} msg;


int main(int argc, char ** argv) {

int s1, res;

/* creation de socket */
s1 = socket(AF_INET, SOCK_DGRAM, 0);
if (s1 ==-1) {
perror("erreur lors de la creation de la socket");
}

struct hostent * hp;
struct sockaddr_in ad_s;
int taille = sizeof(ad_s);

hp = gethostbyname(argv[1]);

memcpy( &ad_s.sin_addr.s_addr, hp -> h_addr, hp -> h_length);
ad_s.sin_family = AF_INET;
ad_s.sin_port = htons(atoi(argv[2]));

//Definition du message a envoyer
msg.pid = getpid();
strcpy(msg.message, argv[3]);

//Envoi du message
res = sendto(s1, &msg, sizeof(msg), 0, (struct sockaddr * ) & ad_s, sizeof(ad_s));
if (res == -1)
perror("l'envoi a echoue");

printf("pid client : %d \tmessage : %s\n",msg.pid,msg.message);

/*En attente de la reponse du serveur*/
res = recvfrom(s1, &msg, sizeof(msg), 0, (struct sockaddr * ) & ad_s, (socklen_t * ) & taille);
if (res == -1)
perror("la reception a echouee");

printf("pid retourne : %d \tmessage : %s\n", msg.pid, msg.message);

return 0;
}