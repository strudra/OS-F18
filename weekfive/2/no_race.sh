#!/bin/bash 

# create a file 
# append 0 if empty
if test ! -f numbers
then
    echo 1 > numbers
fi

# FROM: Hint: use ln file file.lock to lock the data file
# hard link numbers -> numbers.lock
if ln numbers numbers.lock
	then                                                                    
		# run 1000 times
		for i in `seq 1 1000`;
		do
			nmrlast=`tail -1 numbers` # get last nmr.
			nmrlast=$((nmrlast + 1)) # increment it

			echo $nmrlast >> numbers
		done

	#Unlock, remove.
	rm numbers.lock
fi