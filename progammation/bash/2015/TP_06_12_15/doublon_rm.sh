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
