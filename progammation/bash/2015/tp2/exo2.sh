#!/bin/sh
#

read line
while [ "$line" ]; do
    echo "J'ai lu: $line"
    read line
done