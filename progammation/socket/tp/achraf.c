
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include "achraf.h"
#include <netinet/in.h>
#include <arpa/inet.h>

int main( int argc, char ** argv){


    /* declaration des variables */
    char file_ask_byReq[63];
    int sock_svc, sock_fichier, sock_log, res;
    fd_set readdescri;
    struct sockaddr_in ad_port1, ad_port2, ad_c;
    socklen_t taille = sizeof (ad_c);


    /* creation des sockets */
    sock_fichier = socket(AF_INET, SOCK_STREAM, 0);
    if( sock_fichier == -1){
        perror("Erreur a la creation socket file");
        return 0;
    }
    sock_log = socket(AF_INET, SOCK_STREAM, 0);
    if( sock_log == -1){
        perror("Erreur a la creation socket log");
        return 0;
    }
    /* construction des adresses des sockets */
    ad_port1.sin_family = AF_INET;
    ad_port1.sin_port = htons(atoi(argv[1]));
    ad_port1.sin_addr.s_addr = INADDR_ANY;
    memset(ad_port1.sin_zero, 0, 8);
    ad_port2.sin_family = AF_INET;
    ad_port2.sin_port = htons(atoi(argv[2]));
    ad_port2.sin_addr.s_addr = INADDR_ANY;
    memset(ad_port2.sin_zero, 0, 8);

    /* bind des sockets */
    res = bind(sock_fichier, (struct sockaddr *) &ad_port1, sizeof(ad_port1));
    if( res == -1){
        perror("Erreur au bind sock_fichier");
        return 0;
    }
    res = bind(sock_log, (struct sockaddr *) &ad_port2, sizeof(ad_port2));
    if( res == -1){
        perror("Erreur au bind sock_log");
        return 0;
    }


    /* ecoute des ports */
    listen(sock_fichier, 2);
    listen(sock_log, 2);

    /* vide et ajoute des descripteurs*/
    FD_ZERO(&readdescri);
    FD_SET(sock_fichier, &readdescri);
    FD_SET(sock_log, &readdescri);

    res = select((sock_log + 1), &readdescri, NULL, NULL, NULL);
    if( res == -1){
        perror("Echec select descripteur");
        return 0;
    }

    /* si le client se connecte au premier port alors sock_fichier est selectionnee */
    if(FD_ISSET(sock_fichier, &readdescri)) {
        printf("Connexion sur le port:%s\n", argv[1]);

        sock_svc = accept(sock_fichier, (struct sockaddr *) &ad_c, &taille);
        if( sock_svc == -1){
            perror("Erreur au accept file");
            return 0;
        }

         /* log de la requete et transfert du fichier demande */
        memset(file_ask_byReq, 0, sizeof(file_ask_byReq));
        logRequest(sock_svc, &ad_c, file_ask_byReq);
        transFile(sock_svc, file_ask_byReq);
        printf("Transfere du fichier %s\n", file_ask_byReq);
    }

    /* si le client se connecte au second port alors sock_log est selectionnee */
    if(FD_ISSET(sock_log, &readdescri)) {
        printf("Connexion sur le port:%s\n", argv[2]);


        sock_svc = accept(sock_log, (struct sockaddr *) &ad_c, &taille);
        if( sock_svc == -1){
            perror("Erreur au accept log");
            return 0;
        }

            /* transfert du fichier file_log uniquement */
            transFile(sock_svc, "log_file.txt");
            printf("Transfere du fichier log_file.txt\n");
    }


    /* vide et ferme les sockets */
    FD_ZERO(&readdescri);
    res = close(sock_svc);
    if( res == -1){
        perror("Erreur à la fermeture de la socket de service");
        return 0;
    }
    res = close(sock_fichier);
    if( res == -1){
        perror("Erreur à la fermeture de la socket file");
        return 0;
    }
    res = close(sock_log);
    if( res == -1){
        perror("Erreur à la fermeture de la socket log");
        return 0;
    }

    return 0;
} // fin du main

void logRequest(int sock_svc, struct sockaddr_in * ad_clt, char * file_ask_req) {

    int res, ds_flog;
    char * ip_client;
    char tampon[511];
    char file_ask[63];

    /* preparation de la date */
    time_t t;
    struct tm * dat;

    memset(tampon, 0, sizeof(tampon));
    res = read(sock_svc, tampon, sizeof(tampon));

    ip_client = inet_ntoa((struct in_addr *) ad_clt->sin_addr); // conversion @ client en IP

    time(&t);
    dat = localtime(&t); // structure pour la date

    memset(file_ask, 0, sizeof(file_ask));
    sscanf(tampon, "GET /%s HTTP/1.1", file_ask); // recuperation du nom de fichier demande

    /* formation de la chaine de log de la forme : 127.0.0.1  12-4-2013 17:16:50  toto.txt */
    memset(tampon, 0, sizeof(tampon));
    res = sprintf(tampon, "%s  %d-%d-%d %d:%d:%d  %s\n", ip_client, dat->tm_mday, (dat->tm_mon + 1), (dat->tm_year + 1900), dat->tm_hour, dat->tm_min, dat->tm_sec, file_ask);

    /* enregistrement de la requete client dans le log */
    ds_flog = open("log_file.txt", O_CREAT | O_WRONLY | O_APPEND, 0766);
    res = write(ds_flog, tampon, res);
    if( res == -1){
        perror("Erreur a l’ecriture ds_flog");
        return 0;
    }  
    res = close(ds_flog);
    if( res == -1){
        perror("Erreur a la fermeture de la socket ds_flog");
        return 0;
    }  

    /* avant de terminer on recupere le nom du fichier demande pour s'en servir dans la fonction de transfere */
    strcpy(file_ask_req, file_ask);
} // fin logRequest


void transFile(int des_soc, char * file_name) {

    int desc_f, taille_f = 0, t = 0, octet_lu = 0;
    char tampon[511];
    desc_f = open(file_name, O_RDONLY, 0766);
    taille_f = lseek(desc_f, 0, SEEK_END);
    lseek(desc_f, 0, SEEK_SET);

    while (octet_lu < taille_f) {
        memset(tampon, 0, sizeof(tampon));
        t = read(desc_f, tampon, sizeof(tampon));
        res = write(des_soc, tampon, t);
        if( res == -1){
            perror("Erreur à l’ecriture des_soc");
            return 0;
        }        
        octet_lu += t;
    } // fin du while

    res = close(desc_f);
    if( res == -1){
        perror("Erreur a la fermeture de la socket desc_f");
        return 0;
    } 
} // fin transFile
