#!/bin/bash

# the above line is referred as "shebang line", this line starts with #! followed 
# by an absolute path of of the shell which will execute the script

# in shell script programming whatever is in front of # symbol will be considered as a comment

# script to demonstrate basic linux commands:

clear

echo -n "today's date is: "
date +"%d/%m/%Y"

echo "cal of cur month is : "
cal

exit    #exit is used to exit from script 
