#!/bin/bash
echo "Hello, Begin to find."
name="willDelete"

if [ ! -d "$name" ]; then
	mkdir "$name"
	find . -path "./.git" -prune -o -perm /u+x -type f -exec mv {} ./willDelete \;
	echo "Will delete of all this?[y/n]"
	read ans
	if [ "$ans" = "y" ]; then
		echo "OK"
		rm -r $name
	else
		echo "Exit."
	fi
else
	echo "No! The willDelete is existing."
fi
