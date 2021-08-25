#!/bin/bash

# script to do addition of 2 positional parameters

clear

echo "no. of pos params are: $#"
if [ $# -ne 2 ]
then
    echo "invalid no. of pos params to the script: $0"
    exit    # due to this exit script will be exit
fi

res=`expr $1 + $2`
echo "res = $res"
exit












