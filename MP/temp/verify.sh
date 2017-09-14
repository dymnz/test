#!/bin/bash

if [ ! -f ans ]; then
    echo "ans file is not found!"
    exit 1
fi

for i in `seq 0 9`;
do
	echo "Executing "$i"......"

	if [ ! -f test$i.i ]; then
	    echo "test"$i.i" file is not found!"
	    exit 1
	fi

	./ans test$i.i test$i.o

	if [ ! -f test$i.o ]; then
            echo "test"$i.o" file is not found!"
            exit 1
        fi

	DIFF=$(diff <(tail -n +1 test$i.o) <(tail -n +1 gans/gtest$i.o) )
	if [ "$DIFF" != "" ] 
	then
    		echo "	The answer "$i" is not correct."
	else
		echo "	The answer "$i" pass."
	fi
done
