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