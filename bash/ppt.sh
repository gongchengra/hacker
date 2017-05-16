#!/bin/bash
# calc.sh

#算术运算
i=0;
sum=0;
while [ $i -lt 10000 ]
do
    ((i++))
    let "sum += i"
done
echo $i
echo $sum

let i++;
i=$(expr $i + 1)
i=$(echo $i+1|bc)
i=$(echo "$i 1" | awk '{printf $1+$2;}')

##取模：
expr 5 % 2
let i=5%2 && echo $i
echo 5 % 2 | bc
((i=5%2)) && echo $i
##求幂：
let i=5**2 && echo $i  								#25
((i=6**3)) && echo $i   							#216
echo "7^4" | bc										#2401
##进制转换：
echo "obase=10;ibase=8;11" | bc -l 					#9
echo $((2#111111))
##浮点运算：
echo "scale=3; 1/13" | bc 							#0.76
echo "1 13" | awk '{printf("%0.3f\n",$1/$2)}'
echo 1/13100 | bc -l 				#.00007633587786259541
##余弦转角度：
export cos=0.996293; echo "scale=100; a(sqrt(1-$cos^2)/$cos)*180/(a(1)*4)" | bc -l
echo 0.996293 | awk '{ printf("%s\n", atan2(sqrt(1-$1^2),$1)*180/3.1415926535);}'
## 4.934954755411383632719834036931840605159706398655243875372764917732549550415976\
    ## 6011527078286004072131
dc -e '1 1 + p' #2
dc -e '100 100 ^ p'
dc -e '12 13 14 15 * * * p'
dc -e 38699732149506164940799640940658532146962216206167306P #gongchengra@gmail.com
dc -e '[[Enter a number (metres), or 0 to exit]psj]sh[q]sz[lhx?d0=z10k39.370079*.5+0k12~1/rn[ feet ]Pn[ inches]P10Pdx]dx'

#布尔运算
if true;then echo "YES"; else echo "NO"; fi 		#YES
if false;then echo "YES"; else echo "NO"; fi 		#NO
if true && true;then echo "YES"; else echo "NO"; fi #YES
if true || true;then echo "YES"; else echo "NO"; fi #YES
if ! false;then echo "YES"; else echo "NO"; fi		#YES
true && echo $?										#0
false && echo $?                                    #1
if test 5 -eq 5;then echo "YES"; else echo "NO"; fi #YES
if test 5 -ne 5;then echo "YES"; else echo "NO"; fi #NO
if test -n "not empty";then echo "YES"; else echo "NO"; fi #YES
if test -z "not empty";then echo "YES"; else echo "NO"; fi #NO
if test -f /dev; then echo "YES"; else echo "NO"; fi #NO
if test -d /dev; then echo "YES"; else echo "NO"; fi #YES
a=5;b=4;c=6;
if test $a -eq 5 -a $b -eq 4 -a $c -eq 6;
then echo "YES";
else echo "NO";
fi													#YES
if test $a -eq 5 && test $b -eq 4 && test $c -eq 6;
then echo "YES";
else echo "NO";
fi													#YES
if test -f /etc/profile -o -d /etc/profile;
then echo "YES";
else echo "NO";
fi													#YES
if test -f /etc/profile || test -d /etc/profile;
then echo "YES";
else echo "NO";
fi													#YES
i=5;
if test ! $i -lt 5 -a $i -ne 6; then echo "YES"; else echo "NO"; fi #YES
if ! test $i -lt 5 -a $i -ne 6; then echo "YES"; else echo "NO"; fi #YES
if [ $i -eq 5 ]; then echo "YES"; else echo "NO"; fi #YES
str="";
if [ "$str" = "test" ]; then echo "YES"; else echo "NO"; fi #NO

#字符串操作
var="get the length of me"
echo ${var} 										#get the length of me
echo ${#var} 										#20
echo $var | awk '{printf("%d\n", length($0));}' 	#20
echo -n $var | wc -c 								#20
echo -n $var | sed -e 's/[^gt]//g' | wc -c 			#5
echo ${var:0:3}										#get
echo ${var:(-2)} 									#me
echo ${var%% *}										#get
echo ${var% *}										#get the length of
echo ${var##* } 									#me
echo ${var#* }										#the length of me
echo ${var/ /_} 									#get_the length of me
echo ${var// /_} 									#get_the_length_of_me
echo $var | tr " " "_"								#get_the_length_of_me
var_arr=($var) && echo ${var_arr[0]} 				#get
echo ${var_arr[@]} && echo ${#var_arr[@]}			#get the length of me 5
var_arr[5]="new_element" && echo ${#var_arr[@]}     #6
for i in $var; do echo -n $i"_"; done				#get_the_length_of_me_

#shell函数与流程
function foo ()
{
    echo "Arguments work just like script arguments: $@"
    echo "And: $1 $2..."
    echo "This is a function"
    return 0
}

foo "My name is " "Alan"

#!/bin/sh
# vim: set sw=4 ts=4 et:
help()
{
    cat <<HELP
    b2h -- convert binary to decimal
    USAGE: b2h [-h] binarynum
    OPTIONS: -h help text
    EXAMPLE: b2h 111010
    will return 58
HELP
exit 0
}
# in case of error or if -h is given we call the function help:
[ -z "$1" ] && help
[ "$1" = "-h" ] && help
echo "$((2#$1))"

Var=0;
case "$Var" in
    #List patterns for the conditions you want to meet
    0) echo "There is a zero.";;
    1) echo "There is a one.";;
    *) echo "It is not null.";;
esac

#sed and awk
# example
#This is the first line of an example text.
#It is a text with erors.
#Lots of erors.
#So much erors, all these erors are making me sick.
#This is a line not containing any errors.
#This is the last line.
sed -n '/erors/p' example #output lines contain errors
sed '/erors/d' example #delete lines contain errors
sed -n '/^This.*errors.$/p' example #This is a line not containing any errors.
sed '2,4d' example #delete the second to the fourth lines
sed '3,$d' example #delete the third to the end of document.
sed -n '/a text/,/This/p' example #from line 2 to line 5
sed 's/erors/errors/' example #replace the first erors in a line to errors
sed 's/erors/errors/g' example #replace all erors in a line to errors
sed '/Lots/s/erors/errors/g' example #replace all erors to errors when contain Lots
sed '/Lots/!s/erors/errors/g' example #replace erors to errors when not contain Lots
sed 's/^/> /' example #insert > in the beginning of each line
sed 's/$/EOL/' example #insert EOL in the end of each line
sed -e 's/erors/errors/g' -e 's/last/final/g' example #multiple
sed G example #double space
sed '/^$/d;G' example #remove empty lines and add a empty line
sed '/eror/{x;p;x;}' example #insert a line above lines contain eror
sed '/eror/G' example #insert a line below lines contain eror
sed '/eror/{x;p;x;G;}' example #insert a line above and below lines contain error
sed '1!G;h;$!d' example # reverse the line

#awk data
#Beth        4.00        0
#Dan         3.75        0
#Kathy       4.00        10
#Mark        5.00        20
#Mary        5.50        22
#Susie       4.25        18
awk '$3 == 0 {print $1}' emp.data #output employees didn't work
awk '$3 > 0 {print "total pay for", $1, "is", $2*$3}' emp.data #output name salary
awk '{pay = pay + $2*$3};END{print NR, "employees", "Total pay is" pay}' emp.data
awk '$2>maxrate{maxrate=$2;maxemp=$1};END{print "highest rate:",maxrate,"for",maxemp}' emp.data
awk '{names=names $1 " "}END{print names}' emp.data
awk '{print $1, length($1), length($0)}' emp.data
awk '$2 > 6 {n = n+1; pay = pay+$2*$3};
END{if(n>0) print n, "employees, total pay is", pay,"average pay is",pay/n;
else print "no employee are paid more than $6/hour"}' emp.data
awk '{line[NR] = $0}END{for(i=NR;i>0;i--) print line[i]}' emp.data
awk '1;{print ""}' emp.data
awk 'NF{print $0 "\n"}' emp.data
awk 'NF{$0=++a ": " $0};1' emp.data
awk 'NF >= 3' emp.data
awk '$NF >= 3' emp.data
awk '/Beth/{print}' emp.data
awk '/Beth/{n++}; END {print n+0}' emp.data

# print Hello World!
:; ______=$? __=${#______} ____=$[__+__] ________=$[__+____] _____=$[____+____]
     __________=$[____+_____] _________=$[__+__________] ______________=(
            /????/$$/????) ____________=${______________[$______]} 
   _____________=${____________##*/} _______________=(${____________//\// })
          ________________=${_______________: -$__:$__}$_____________
           ___________________=${________________:$______:$________}
   ___________=${_____________:$______:$__} _________________=${___________^}
     . <($___________________<<<__________________=\({$_________________..\
${___________}}\))&&_______=(${__________________[@]:$______:$____$__________})
  ___=(${_______[@],,})&&${___[$_____]}${___[$____]}${___[$_________]}${___[
$__$_____]} -${___[$_____]} ${_______[ $_________]}${___[${_____}]}${___[$__$__
]}${___[$__$__]}${___[$__$_____]} ${_______[$____$____]}${___[$__$_____]}${___[
$__$_________]}${___[ $__$__]}${___[$________]}\\$______$[$_____#$____$____$__]
