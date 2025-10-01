#! /bin/bash

./prog < input1.txt > output.txt
cmp output.txt $2
if [ $? == 0 ]; then
	echo "Test Passed"
else
	echo "Test Failed"
fi
