cr de bash

			#detecte ipv4 en exa
#!/bin/bash
echo "lol"
ipv4="0xC0A80101"
echo $ipv4
expr "$ipv4" : "0x[0-2 A-C][0-9 A-F]" #\{1,3\}$
echo $?


			#renome les JPG en jpeg
#!/bin/bash
for var in *;
do
	echo $var
	case $var in
		*.JPG) mv $var ${var%.JPG}.jpeg;;
		*.TIF) mv $var ${var%TIF}.tif;;
	esac
	echo $var
done



			#supprime les dossier en doubles
#!/bin/bash
for var in *;
do
	if [ `ls $var |wc -l` -eq 0 ]
	 then echo "voulez vous effacer "$var;
	 read lol;
	 case $lol in
	 	y) echo ok `rmdir $var` ;;
		n) echo ok batard ;;
esac
	 
	fi
done



			#decoupe un fichier
#!/bin/bash
echo $1 $2 $#;
if [ $# == 2 ] && [ $1 != NULL ] && [ $2 != NULL ] 
	then echo ok batard;
	
fi

test1=`expr "$2" : "^[0-9]\{1,\}$"`;

 if [ $? == 0 ]
 	then echo ok

 else
 	echo chifre pour le deuxieme argument
fi
split -b $2k $1

nfichie= `expr `stat -c '%s' lol` / $2 * 1024 `
echo $nfichie
#asep -r -i $1 -o $1 cript -s 7150 1234 4321




