#!/bin/bash

REPLACE_FROM_FILENAME=$1

# Verify the number of arguments given
# Display an error message if the filename argument is not given
# Display another error message if the file is not found
# Exit the shell script with a status of 1 using exit 1 command.
[ $# -eq 0 ] && { echo "Usage: $0 filename key [key ...]"; exit 1; }
shift
[ $# -eq 0 ] && { echo "Usage: $0 filename key [key ...]"; exit 1; }


while test ${#} -gt 0
do
    sed -i "s/$var/,$var/g" $REPLACE_FROM_FILENAME
    [ $? -eq 2 ] && { echo "$REPLACE_FROM_FILENAME does not exist!"; exit 2; }
    shift
done

