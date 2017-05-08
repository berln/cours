#!/bin/bash
var=test:test1:fichier.la
echo $var
echo ${var##*:}
echo ${var%:*}
for test in *;
do
	echo $test
done

read condi
case $condi in
	*.jpg) echo immage
esac



while read line; do
	echo $line
	if [ $line = exit ]
	then
		break
	fi
done
