#!/bin/sh
#
echo "$# arguments ont ete passes au script"
echo "arg0 = $0"
echo "arg1 = $1"
echo "arg2 = $2"
echo '$* vaut' $*
echo $* | wc 


i=1
find $1 | read line
while [ "$line" ]; do
    echo "lol"$line
done