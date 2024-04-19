#!/bin/bash
function fibannacci(){
	limit=$(($1-2))
	a=0
	b=1
	echo "Fibannacci series"
	echo -n "$a,$b"
	for((i=0;i<$limit;i++))do
	c=$((a+b))
	echo -n ",$c"
	a=$b
	b=$c
	done
	echo ""
}
echo "How many terms to be generated"
read n
fibannacci $n
