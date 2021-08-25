#!/bin/bash

# script to write a function to print table of given number

function table( )
{
    echo "table of $1 is : "
    for i in {1..10..1}
    do
        res=`expr $1 \* $i`
        echo "$res"
    done
}


clear
echo "script started ...."

echo -n "enter the number : "
read num

#function calling => way-1 => call function by its name and pass value
# in this way of function calling function do not returns anything into the calling area
# table $num

#function calling => way-2 => call function by its name and pass value and get the return value from the function
# in this way of function calling function returns value into the calling area
tab=$( table $num )

echo "tab is: "
echo "$tab"

echo "script exited ...."

exit

# in way-1 of function calling => echo statement/command is used for printing value purpose
# in way-2 of function calling => echo statement/command is used for storing value in a collection purpose
