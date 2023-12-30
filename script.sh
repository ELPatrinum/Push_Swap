#!bin/bash

max=10
for((i=0; i < $max; i++))
do
	arg=$(seq 0 2| sort -R)
	./push_swap $arg | ./checker_linux $arg
done
