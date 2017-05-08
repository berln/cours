#!/bin/sh
#
read ligne
lol= `expr $line`
echo "Ici PID $$, j'ai lu: $lol" 1>&2