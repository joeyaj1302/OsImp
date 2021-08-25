#!/bin/bash

# the above line is called as "shebang line" => this line contains
# an absolute path of shell program which will execute the script.

# script to do addition of two numbers:

clear

echo -n "enter the value of n1: "
read n1 # read command is used to scan the value of variable from user

echo -n "enter the value of n2: "
read n2

res=`expr $n1 + $n2`
echo "res = $res"

exit
