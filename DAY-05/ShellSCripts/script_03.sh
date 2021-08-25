#!/bin/bash

# script to calculate area of rectangle
# in shell script programming langauge variables are like container which may contains
# any type of value.

clear

echo -n "enter the length : "
read len    # len is a user defined variable

echo -n "enter the breadth : "
read br     # br is a user defined variable

area=`expr $len \* $br`  # area is a user defined variable
echo "area of rectangle is : $area"

exit








