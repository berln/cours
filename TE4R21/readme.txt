Paramétrage des stations
Revenir à WiFi
PHY/MAC

Lister les réseaux radio environnants : iwlist wlan0 scan

Configurer les couches PHY/MAC de la carte réseau wireless : iwconfig wlan0

Activer/désactiver la carte réseau : ifconfig wlan0 up/down
IP

Configurer la carte réseau couche IP : ifconfig wlan0 192.168.1.100

Ajouter une route statique vers le réseau 192.168.2.0 : route add -net 192.168.2.0 netmask 255.255.255.0 gw 192.168.1.1 dev wlan0
Application

Démarrer le serveur ftp : /etc/init.d/vsftpd start
Modifié le: mardi 14 avril 2015, 08:26