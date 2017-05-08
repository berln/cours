#!/bin/bash
#
i=1
read line
while [ "$line" ]; do
    echo "fichier n"$i
    $i=i++
    chemin=${line%/*}
	echo $chemin
	nom=${line##*/}
	echo $nom
    read line
done