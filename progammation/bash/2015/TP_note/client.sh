#!/bin/bash
#

a=`echo $(( ( RANDOM % 2000 )  - 1000 ))`;
b=`echo $(( ( RANDOM % 2000 )  - 1000 ))`;
echo $a + $b;
read line;
echo "Ici PID $$, j'ai lu: $line" 1>&2;