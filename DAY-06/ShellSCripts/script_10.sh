#!/bin/bash

# script to add all positional params

clear

sum=0

echo "sum of all positional params is: "

for var in $*
do
    sum=`expr $sum + $var`
done

echo "sum = $sum"


exit