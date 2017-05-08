#!/bin/bash
#
i=1
read line
while [ "$line" ]; do
    echo "fichier n"$i
    i=$((i+1))
    chemin=${line%/*}
	echo $chemin
	name=${line##*/}
	if [ $name = $namea ]
		then
		echo "doublon"
	fi
	echo "nama" $namea
	namea=$name
	echo "name" $name
    read line
done