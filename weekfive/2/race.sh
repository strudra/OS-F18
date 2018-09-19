#!/bin/bash 

# create a file 
# append 0 if empty
if test ! -f numbers
then
    echo 1 > numbers
fi

# no locking in this case 
# because we don't need to race.
# use 1000 as example.
for i in `seq 1 1000`;
do
	nmrlast=`tail -1 numbers` # get last nmr.
	nmrlast=$((nmrlast + 1)) # increment it

	echo $nmrlast >> numbers
done