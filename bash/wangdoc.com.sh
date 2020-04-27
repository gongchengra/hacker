#!/usr/bin/env bash -x
# https://wangdoc.com/bash/index.html

#echo "$# arguments inputted. They are"
#for i in "$@";
#do
#echo $i
#done

#echo ""
#echo "Or"
#while["$1" != ""]; do
#echo "$# more."
#echo $1
#shift
#done

while getopts 'lha:' OPTION; do
    case "$OPTION" in
        l)
            echo "linux config" ;;
        h)
            echo "h for help" ;;
        a)
            avalue="$OPTARG"
            echo "The value is $OPTARG" ;;
        ?)
            echo "usage: $(basename $0) [-l] [-h] [-a somevalue]" >&2
            exit 2 ;;
    esac
done

txt(){
    echo -n "Input some text: "
    read txt
    echo "Your input: $txt"
}
#txt

fn(){
    echo please input your firstname and lastname
    read fn ln
    echo "hi $fn, $ln!"
}
#fn

rep(){
    echo input one or more value
    read
    echo "reply = $REPLY"
}
#rep

myline(){
    filename=t.txt
    while read myline; do
        echo $myline
    done < $filename
}
#myline

readt() {
    echo "input some text in 3 seconds"
    if read -t 3 response; then
        echo "user responsed"
    else
        echo "user has gone with wind"
    fi
}
#readt

readp(){
    read -p "Input some values: " val
    echo "Your inputs are $val"
}
#readp

reada(){
    read -p "Input to array: " -a names
    echo ${names[0]}
}
#reada

readn(){
    read -p "Input month names: " -n 3 mon
    echo
    echo ${mon^^}
}
#readn

## tab to autocomplete
reade(){
    read -p "Input filename: " -e filename
    echo $filename
}
#reade

ifs() {
    FILE=/etc/passwd
    read -p "Enter a username: " username
    fileinfo="$(grep $username $FILE)"
    OLD_IFS="$IFS"
    if [ -n "fileinfo" ]; then
        IFS=":" read user pw uid gid name home shell <<< $fileinfo
        echo "User = $user"
        echo "UID = $uid"
        echo "GID = $gid"
        echo "Name = $name"
        echo "Home = $home"
        echo "Shell = $shell"
    else
        echo "No such user $username" >&2
        exit 1
    fi
    IFS=$OLD_IFS
}
#ifs

cond(){
    read -p "Enter a number less than 3: " num
    if [ $num == 0 ]; then
        echo 0;
    elif [ $num == 1 ]; then
        echo 1;
    elif [ $num == 2 ]; then
        echo 2;
    else
        echo "invalid number";
    fi
}
#cond

test3(){
    test -f /etc/hosts && echo true
    [ -f /etc/hosts ] && echo true
    [[ -f /etc/hosts ]] && echo true
    echo $?
}
#test3

<< COMMENT
[ -a file ]：如果 file 存在，则为true。
[ -b file ]：如果 file 存在并且是一个块（设备）文件，则为true。
[ -c file ]：如果 file 存在并且是一个字符（设备）文件，则为true。
[ -d file ]：如果 file 存在并且是一个目录，则为true。
[ -e file ]：如果 file 存在，则为true。
[ -f file ]：如果 file 存在并且是一个普通文件，则为true。
[ -g file ]：如果 file 存在并且设置了组 ID，则为true。
[ -G file ]：如果 file 存在并且属于有效的组 ID，则为true。
[ -h file ]：如果 file 存在并且是符号链接，则为true。
[ -k file ]：如果 file 存在并且设置了它的“sticky bit”，则为true。
[ -L file ]：如果 file 存在并且是一个符号链接，则为true。
[ -N file ]：如果 file 存在并且自上次读取后已被修改，则为true。
[ -O file ]：如果 file 存在并且属于有效的用户 ID，则为true。
[ -p file ]：如果 file 存在并且是一个命名管道，则为true。
[ -r file ]：如果 file 存在并且可读（当前用户有可读权限），则为true。
[ -s file ]：如果 file 存在且其长度大于零，则为true。
[ -S file ]：如果 file 存在且是一个网络 socket，则为true。
[ -t fd ]：如果 fd 是一个文件描述符，并且重定向到终端，则为true。 这可以用来判断是否重定向了标准输入／输出错误。
[ -u file ]：如果 file 存在并且设置了 setuid 位，则为true。
[ -w file ]：如果 file 存在并且可写（当前用户拥有可写权限），则为true。
[ -x file ]：如果 file 存在并且可执行（有效用户有执行／搜索权限），则为true。
[ file1 -nt file2 ]：如果 FILE1 比 FILE2 的更新时间最近，或者 FILE1 存在而 FILE2 不存在，则为true。
[ file1 -ot file2 ]：如果 FILE1 比 FILE2 的更新时间更旧，或者 FILE2 存在而 FILE1 不存在，则为true。
[ FILE1 -ef FILE2 ]：如果 FILE1 和 FILE2 引用相同的设备和 inode 编号，则为true。
COMMENT

: '
Another way to write comment.
'

brc() {
    file=~/.bashrc
    if [ -e "$file" ]; then
        if [ -f "$file" ]; then echo "regular file"; fi
        if [ -d "$file" ]; then echo "directory"; fi
        if [ -r "$file" ]; then echo "readable"; fi
        if [ -w "$file" ]; then echo "writable"; fi
        if [ -x "$file" ]; then echo "executable"; fi
    else echo "$file doesn't exist."; exit 1;
    fi
}
#brc

<< COMMENT
[ string ]：如果string不为空（长度大于0），则判断为真。
[ -n string ]：如果字符串string的长度大于零，则判断为真。
[ -z string ]：如果字符串string的长度为零，则判断为真。
[ string1 = string2 ]：如果string1和string2相同，则判断为真。
[ string1 == string2 ] 等同于[ string1 = string2 ]。
[ string1 != string2 ]：如果string1和string2不相同，则判断为真。
[ string1 '>' string2 ]：如果按照字典顺序string1排列在string2之后，则判断为真。
[ string1 '<' string2 ]：如果按照字典顺序string1排列在string2之前，则判断为真。
COMMENT

st() {
    read -p "Enter your answer: " ans
    if [ -z $ans ]; then echo "no answer" >&2; exit 1; fi
    if [ "$ans" == "yes" ] || [ "$ans" == "no" ] || [ "$ans" == "maybe" ]; then
        echo "Your answer is $ans";
    else
        echo "unkown answer.";
    fi
}
#st

<< COMMENT
[ integer1 -eq integer2 ]：如果integer1等于integer2，则为true。
[ integer1 -ne integer2 ]：如果integer1不等于integer2，则为true。
[ integer1 -le integer2 ]：如果integer1小于或等于integer2，则为true。
[ integer1 -lt integer2 ]：如果integer1小于integer2，则为true。
[ integer1 -ge integer2 ]：如果integer1大于或等于integer2，则为true。
[ integer1 -gt integer2 ]：如果integer1大于integer2，则为true。
COMMENT

nt() {
    read -p "Enter an integer: " int
    if [ -z "$int" ]; then echo "Empty input." >&2; exit 1; fi
    if [ $int -lt 0 ]; then echo "$int is negative.";
    elif [ $int -eq 0 ]; then echo "$int is 0";
    else echo "$int is positive.";fi
    if [ $((int %2)) -eq 0 ]; then echo "$int is even.";
    else echo "$int is odd"; fi
}
#nt

# [[ string1 =~ regex ]] 这种判断形式，支持正则表达式。
rt() {
    read -p "Enter an integer: " int
    if [[ "$int" =~ ^-?[0-9]+$ ]]; then
        echo "$int is an integer"
    else
        echo "$int is not an integer"
    fi
}
#rt

<<COMMENT
通过逻辑运算，可以把多个test判断表达式结合起来，创造更复杂的判断。
三种逻辑运算AND，OR，和NOT，都有自己的专用符号。
AND运算：符号&&，也可使用参数-a。
OR运算：符号||，也可使用参数-o。
NOT运算：符号!。
使用否定操作符!时，最好用圆括号确定转义的范围。
if [ ! \( $INT -ge $MIN_VAL -a $INT -le $MAX_VAL \) ]; then
        echo "$INT is outside $MIN_VAL to $MAX_VAL."
    else
            echo "$INT is in range."
fi
COMMENT

tr() {
    min=1
    max=100
    read -p "Enter an integer: " int
    if [[ "$int" =~ ^-?[0-9]+$ ]]; then
        if [[ $int -ge min && $int -le max ]]; then
            echo "$int is within $min and $max"
        else
            echo "$int is out of range."
        fi
    else
        echo "$int is not an integer"
    fi
}
#tr

<<COMMENT
Bash 还提供了((...))作为算术条件，进行算术运算的判断。
注意，算术判断不需要使用test命令，而是直接使用((...))结构。这个结构的返回值，决定了判断的真伪。
如果算术计算的结果是非零值，则表示判断成立。这一点跟命令的返回值正好相反，需要小心。
COMMENT

at() {
    if((1)); then echo true; fi
    if((0)); then echo false; else echo true; fi
    read -p "Input a number: " int
    if [[ $int =~ ^-?[0-9]+$ ]]; then
        if (($int < 0)); then echo "$int < 0";fi
        if (($int > 0)); then echo "$int > 0";fi
        if (($int == 0)); then echo "$int = 0";fi
        if (( (($int % 2)) == 0 ));then echo "$int is even";
        else echo "$int is odd"; fi
    else
        echo "$int is not an integer"
    fi
}
#at

logic() {
    [ -d tmp ] || mkdir tmp && cd tmp && touch tt.tt && echo "this is a test file" >> tt.tt
    [ -d tmp ] && cd tmp && [ -f tt.tt ] && rm tt.tt && cd .. && rmdir tmp
}
#logic

ct() {
    rand=$((${RANDOM}%100))
    while [ 1 -gt 0 ]; do
        read -p "Enter a number within 0 and 100: " guess
        if (($guess < $rand)); then flag=-1;fi
        if (($guess == $rand)); then flag=0;fi
        if (($guess > $rand)); then flag=1;fi
        case $flag in
            1 ) echo "Too big" ;;
            0 ) echo "You are right" && break ;;
            -1 ) echo "Too small";;
        esac
    done
}
#ct

os() {
    OS=$(uname -s)
    case "$OS" in
        FreeBSD) echo "This is FreeBSD" ;;
        Darwin) echo "This is Mac OSX" ;;
        AIX) echo "This is AIX" ;;
        Minix) echo "This is Minix" ;;
        Linux) echo "This is Linux" ;;
        *) echo "Failed to identify this OS" ;;
    esac
}
#os

<<COMMENT
case的匹配模式可以使用各种通配符，下面是一些例子。
    a)：匹配a。
    a|b)：匹配a或b。
    [[:alpha:]])：匹配单个字母。
    ???)：匹配3个字符的单词。
    *.txt)：匹配.txt结尾。
    *)：匹配任意输入，通过作为case结构的最后一个模式。
COMMENT

al() {
    read -p "输入一个字母或数字 > " character
    case $character in
        [[:lower:]] | [[:upper:]] ) echo "输入了字母 $character"
            ;;
        [0-9] )                     echo "输入了数字 $character"
            ;;
        * )                         echo "输入不符合要求"
    esac
}
#al

<<COMMENT
Bash 4.0之前，case结构只能匹配一个条件，然后就会退出case结构。
Bash 4.0之后，允许匹配多个条件，这时可以用;;&终止每个条件块。
COMMENT

mc() {
	read -n 1 -p "Type a character > "
	echo
	case $REPLY in
		[[:upper:]])    echo "'$REPLY' is upper case." ;;&
		[[:lower:]])    echo "'$REPLY' is lower case." ;;&
		[[:alpha:]])    echo "'$REPLY' is alphabetic." ;;&
		[[:digit:]])    echo "'$REPLY' is a digit." ;;&
		[[:graph:]])    echo "'$REPLY' is a visible character." ;;&
		[[:punct:]])    echo "'$REPLY' is a punctuation symbol." ;;&
		[[:space:]])    echo "'$REPLY' is a whitespace character." ;;&
		[[:xdigit:]])   echo "'$REPLY' is a hexadecimal digit." ;;&
	esac
}
#mc

wt() {
    num=0
    while [ "$num" -lt 10 ]; do
        echo $num
        num=$((num+1))
    done

    # loop forever
    #while true; do echo 'Hi, while looping ...'; done

    #nothing, since while look at last res
    while true; false; do echo 'Hi, looping ...'; done
}
#wt

ut() {
    n=0
    until [ $n -ge 10 ]; do
        echo $n
        n=$((n+1))
    done
}
#ut

fit() {
    count=0
    for i in $(cat ~/.bash_profile); do
        count=$((count + 1))
        echo "Word $count ($i) contains $(echo -n $i | wc -c) characters"
    done
    for f in "$@"; do
        echo $f
    done
}
#fit

ft() {
    sum=0
    for (( i=0;i<5;i++ )); do
        echo $i
        sum=$((sum+i))
    done
    echo "sum = $sum"
}
#ft

bt() {
    for n in 1 2 3 4 5 6; do
        echo $n
        if [ "$n" -eq "3" ]; then
            break
        fi
    done
}
#bt

ct() {
    while read -p "Enter filename: " filename; do
        if [ ! -e "$filename" ]; then
            echo "$filename doesn't exist"
            continue
        fi
        echo "$filename is a valid file"
    done
}
#ct

sele() {
    select brand in Samsung Sony iphone symphony Walton; do
        echo $brand
    done
}
#sele

hello() {
    echo "hello $1"
}
#hello world
#hello tom

today() {
    echo -n "Today's date is: "
    date +"%A, %B %-d, %Y"
}
#today

unset -f today

# cann't find today command
#today

#find declared functions
#declare -f
#find declared function names
#declare -F

function alice () {
    echo "alice: $@"
    echo "$0: $1 $2 $3 $4"
    echo "$# arguments"
}
#alice come to wonderland

function log_msg {
  echo "[`date '+ %F %T'` ]: $@"
}
#log_msg "This is sample log message"

fnre() {
    local r=$RANDOM
    echo $r
    return $r
}
#fnre
#echo $?
#echo $(fnre)

arr(){
    set -x
    arr[0]=$RANDOM
    arr[1]=$RANDOM
    arr[2]=$RANDOM
    echo ${arr[0]}
    echo ${arr[1]}
    echo ${arr[2]}
    arr=(a b c)
    echo ${arr[0]}
    echo ${arr[1]}
    echo ${arr[2]}
    echo ${arr[@]}
    array=([2]=c [0]=a [1]=b)
    echo ${array[0]}
    echo ${array[1]}
    echo ${array[2]}
    days=(Sun Mon Tue Wed Thu Fri Sat)
    echo ${days[@]}
    for d in ${days[@]};do
        echo $d
    done
    echo "acts"
    activities=( swimming "water skiing" canoeing "white-water rafting" surfing )
    i=0
    for act in ${activities[@]}; do
        echo "$i: $act"
        i=$((i+1))
    done
    echo ${#activities[*]}
    hobbies=("${activities[@]}" diving)
    j=0
    for act in "${hobbies[@]}"; do
        echo "$j: $act ${#hobbies[$j]}"
        j=$((j+1))
    done
    echo ${#hobbies[*]}
    echo ${#hobbies[@]}
    arr=([5]=a [9]=b [23]=c)
    echo ${!arr[@]}
    echo ${!arr[*]}
    for e in ${!arr[@]}; do
        echo ${arr[e]}
    done
    food=(apples bananas cucumbers dates eggs fajitas grapes)
    echo ${food[@]}
    echo ${food[@]:0:2}
    echo ${food[@]:2:8}
    echo ${food[@]:4}
    food+=(rice noodle)
    echo ${food[@]}
    food[0]=''
    unset food[2]
    echo ${food[@]}
    unset food
}
#arr

sett() {
    # set -u 脚本在头部加上它，遇到不存在的变量就会报错，并停止执行。
    # set -o nounset
    set -u
    # set -x 用来在运行结果之前，先输出执行的那一行命令。
    # set -o xtrace
    set -x
    #arr
    set +x

    # set -e 使得脚本只要发生错误，就终止执行。
    # set -e有一个例外情况，就是不适用于管道命令。
    # set -o errexit
    set -e
    foo || echo a
    echo bar
    # set -o pipefail 只要一个子命令失败，整个管道命令就失败，脚本就会终止执行。
    set -eo pipefail
    foo || echo a
    echo bar
    # set -n：等同于set -o noexec，不运行命令，只检查语法是否正确。
    # set -f：等同于set -o noglob，表示不对通配符进行文件名扩展。
    # set -v：等同于set -o verbose，表示打印 Shell 接收到的每一行输入。
    # 上面重点介绍的set命令的四个参数，一般都放在一起使用。
    # set -euxo pipefail
}
#sett

debug(){
    export PS4='$LINENO + '
    dir_name=/path/not/exist
    # 下面两行会删光当前目录的文件
    #    cd $dir_name
    #    rm *
    # 删光用户主目录的文件
    #     cd $dir_name && rm *
    [[ -d $dir_name ]] && cd $dir_name && rm *
    # bash的-x参数可以在执行每一行命令之前，打印该命令。
    num=1
    if [ $num == 1 ]; then
        echo $num is 1
    else
        echo $num is not 1
    fi
    echo "This is line $LINENO"
    echo "func1: FUNCNAME0 is ${FUNCNAME[0]}"
    echo "func1: FUNCNAME0 is ${FUNCNAME[1]}"
    echo "func1: FUNCNAME0 is ${FUNCNAME[2]}"
    echo
    echo "func1: BASH_SOURCE0 is ${BASH_SOURCE[0]}"
    echo "func1: BASH_SOURCE1 is ${BASH_SOURCE[1]}"
    echo "func1: BASH_SOURCE2 is ${BASH_SOURCE[2]}"
    echo
    echo "func1: BASH_LINENO is ${BASH_LINENO[0]}"
    echo "func1: FUNCNAME is ${FUNCNAME[0]}"
    echo "func1: BASH_SOURCE is ${BASH_SOURCE[1]}"
}
#debug

func1(){
    debug
}
#func1

mktmp() {
    # 脚本遇到EXIT信号时，就会执行rm -f "$TMPFILE"
    trap 'rm -f "$tmp"' exit
    tmp=$(mktemp) || exit 1
    echo "$tmp created"
    ls /etc > $tmp
    if grep -qi "kernel" $tmp; then
        echo 'find'
    fi
    # make temp directory
    #    tmp=$(mktemp -d)
    # -p not work in mac
    # tmp=$(mktemp -p /tmp)
}
#mktmp

#    如果trap需要触发多条命令，可以封装一个 Bash 函数。
#function egress {
#    command1
#    command2
#    command3
#}
#trap egress EXIT

