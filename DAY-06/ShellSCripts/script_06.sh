#!/bin/bash

# script :
# enter filepath from the user check whether filepath is valid or invalid
# if filepath is invalid then print message as "invalid filepath"
# if filepath is valid:
#   if filepath is regular file => display its contents (by using "cat" command )
#   if filepath is a directory file => display its contents (by using "ls" command )
# print message as "filepath is neither regular file nor directory file"

clear

echo -n "enter the filepath :"
read filepath

if [ -e $filepath ] #if filepath is valid
then
    if [ -f $filepath ] # if filepath is a regular file 
    then
        echo "$filepath is a regular file & its contents are:"
        cat $filepath   # display its contents by using "cat" command
    elif [ -d $filepath ] # if filepath is a directory file 
    then
        echo "$filepath is a directory file & its contents are:"
        ls -l $filepath   # display its contents by using "ls" command
    else
        echo "$filepath is a neither regular file nor directory file"
    fi
else    # if filepath is invalid
    echo "$filepath is a invalid"
fi


