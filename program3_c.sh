#!/bin/bash
if [ "$#" -ne 1 ] ;then
	echo "Usage:$0<file_name>"
	exit 1
fi
file_name="$1"
if [ ! -e "$file_name" ]; then
	echo "File not found"
	exit 1
fi
echo "Contents of $file_name"
cat "$file_name"
