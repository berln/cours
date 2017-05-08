#!/bin/bash
for var in *;
do
	echo $var
	case $var in
		*.JPG) mv $var ${var%.JPG}.jpeg;;
		*.TIF) mv $var ${var%TIF}.tif;;
	esac
	echo $var
done
