#!/bin/bash
prefix=$1
a=1
for i in `ls *`; do
    new=$(printf "$prefix%02d.jpg" "$a")
    mv -i -- "$i" "$new"
    let a=a+1
done
