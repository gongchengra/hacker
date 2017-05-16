#!/bin/bash
# calc.sh
i=0;
sum=0;
while [ $i -lt 10000 ]
do
    ((i++))
    let "sum += i"
done
echo $i
echo $sum
