#!/bin/bash

if [ -z "$1" ]; then
	echo "You need to pass the folder name as an argument!";
	exit -1;
fi


function strstr() {
	# Does $1 contain $2 ?
	# $1 = haystack, $2 = needle
	echo "$1"
	echo "$2"
	[ "${1#*$2*}" = "$1" ] && return 1
	return 0
}



for file in "$(pwd)"/$1/*; do
	needle=_fixed
	strstr "$file" "$needle" && continue || \
		perl -pne 's/\x0d\x0a/\x0a/g' < "$file" > "$file"$needle
done
