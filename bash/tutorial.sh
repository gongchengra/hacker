#!/bin/bash
echo "Hello World!"

NAME='Alan'
echo Hello, ${NAME}.
echo 'My name is ${NAME}.'
echo "My name is ${NAME}."

echo 'Here is $50.'
echo "Here is $50."
echo "Here is \$50."

USERNAME="Alan Gong"
echo "My name is ${USERNAME}. People call me ${USERNAME:0:4}."

declare -a FRIENDS=("Kris" "Robin" "Mancy")
echo ${#FRIENDS[*]}
echo ${FRIENDS[*]}
FRIENDS=(${FRIENDS[*]} "David")
echo ${FRIENDS[*]}
FRIENDS=(${FRIENDS} "Hao")
echo ${FRIENDS[*]}

expr 2 + 3 \* 5

# equal and or lt gt
A=10
B=15
if [ $A -eq $B ]
then
    echo "True"
else
    echo "False"
fi

if [ $A -gt 0 -a $A -lt $B ]
then
    echo "True"
else
    echo "False"
fi

if [ $A -lt 0 -o $A -gt $B ]
then
    echo "True"
else
    echo "False"
fi

#while and for loop
echo "Shall we begin the demo?(y/n)"
#read ANS
ANS='y'
C=0
declare -a D=(0)
if [ $ANS = 'y' ]
then
    echo "Output the results of the while loop"
    while [ $C -lt 10 ]
    do
        echo $C
        C=$(expr $C + 1)
        D=(${D[*]} $C)
    done
else
    echo "Not ready for demo yet."
fi

echo "Output the results of the for loop"
for i in ${D[*]}
do
    echo $i
done

#function
hello(){
echo "hello"
}
hello

intro(){
    echo "There are $1 people here, they are $2, $3."
}
intro 2 'Steven' 'Jobs'

returnval() {
    A=$(expr 10 \/ 5)
    return $A
}
returnval
RET=$?
echo $RET

#sed
#FILE1=sed1.log
#sed -i.tmp "/^$/d" $FILE1
#sed -e "/^$/d" $FILE1
#sed -e "1,3d" $FILE1
#sed -e "s/But/but/" $FILE1
FILE2=sed2.log
#sed -i.tmp 's/^[ 1-3]//' $FILE2
#sed -i.tmp 's/^[. 1-9]*//;s/[;.!]$/ ENDING/' $FILE2
#sed -e 's/some.*//' $FILE2
#sed -e '/some/d' $FILE2
#sed -e 's/ENDING$//' $FILE2
#sed -i.tmp '3 a\
#    add random text in line 3' $FILE2
#sed -i.tmp '5 a add random text in line 5' $FILE2
#sed -i.tmp '$ a add random text in end of file' $FILE2
#sed -i.tmp '/text/ i INSERT TEXT BEFORE EVERY LINE CONTAINS text' $FILE2

#grep
#list
#grep -l "text" $FILE2
#count
#grep -c "text" $FILE2
#line number
#grep -n "text" $FILE2
#not match
#grep -vn "text" $FILE2
grep "file\|But" $FILE2






