#!/bin/bash

# script to calculate area of the circle

# area of the circle = PI*rad*rad

clear

PI=3.14

echo -n "enter the radius : "
read rad

area=`echo "$PI * $rad * $rad" | bc`

echo "area of circle = $area"

exit


