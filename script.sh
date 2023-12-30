#!bin/bash

max=100
for((i=0; i < $max; i++))
do
	arg=$(seq 0 99| sort -R)
	./push_swap $arg | ./checker_linux $arg
done
