#!/bin/bash
ln fichier1 /chemin/fichier2
#cree un autre lien vers le fichier, prinsipe de lien symbolique

#connaitre le nom et le chemin d'un fichier
basename ; dearname

rm fichier #detruit les acces au fichier il faut donc detruire tout les liens pour supprimer le fichier

find -samefile nomfichier
echo {`ls`}

# droits fichier
chmode 755 #ajoute les droits
umask 177 # permet de retirer les droits
