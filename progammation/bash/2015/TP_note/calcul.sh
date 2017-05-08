#!/bin/sh
#

read line
calc=`expr $line`
echo "Ici PID $$, j'ai lu: $calc" 1>&2
