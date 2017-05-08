#!/bin/sh
#
x=$1
chemin=${x%/*}
echo $chemin
nom=${x##*/}
echo $nom