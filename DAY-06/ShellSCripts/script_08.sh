#!/bin/bash

# script to print name of only executable files in a cur dir

clear

echo "executable files in a cur dir are: "

for filepath in `ls`
do
    if [ -x $filepath ] # if file has execute perm
    then
        echo "$filepath"
    fi
done


exit

