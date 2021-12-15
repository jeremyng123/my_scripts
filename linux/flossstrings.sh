#!/bin/bash

for filename in $(pwd)/$1/*; do
	echo $filename
	floss -n 6 -x "$filename" > "$filename".txt
done
