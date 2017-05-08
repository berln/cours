#!/bin/bash
echo "lol"
ipv4="0xC0A80101"
echo $ipv4
expr "$ipv4" : "0x[0-2 A-C][0-9 A-F]" #\{1,3\}$
echo $?