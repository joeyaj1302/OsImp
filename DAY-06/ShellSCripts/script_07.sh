#!/bin/bash

# script to print table of a given number

clear

echo -n "enter the number   : "
read num

echo "while => table of $num is : "
i=1
while [ $i -le 10 ]
do
    res=`expr $num \* $i`
    echo "$res"
    i=`expr $i + 1` # i++ => i = i + 1
done


echo "until => table of $num is : "
i=1
until [ $i -gt 10 ]
do
    res=`expr $num \* $i`
    echo "$res"
    i=`expr $i + 1` # i++
done


echo "for => table of $num is : "
#for i in 1 2 3 4 5 6 7 8 9 10

for i in {1..10..1}
do
    res=`expr $num \* $i`
    echo "$res"
done

exit


