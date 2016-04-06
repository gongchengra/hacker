#!/bin/bash
#for arg in "$@";do
#    echo "$arg";
#done

#if [[ "$1" == d* ]]; then
#    echo $1
#fi

#function quit {
#exit
#}
#function hello {
#echo Hello!
#}
#hello
#quit
#echo foo

#OPTIONS="Hello Quit"
#select opt in $OPTIONS; do
#    if [ "$opt" = "Quit" ]; then
#        echo done
#        exit
#    elif [ "$opt" = "Hello" ]; then
#        echo Hello World
#    else
#        clear
#        echo bad option
#    fi
#done

#echo Please, enter your name
#read NAME
#echo "Hi $NAME!"

#echo Please, enter your firstname and lastname
#read FN LN
#echo "Hi! $LN, $FN !"

if [[ "$1" == d* ]]; then
    echo $1
fi


