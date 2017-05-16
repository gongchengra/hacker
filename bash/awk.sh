#!/bin/bash
ps |  grep $$  |  awk '{print $4}'  
free -m | grep 'Mem:' | awk '{print $3-$6-$7}'
netstat -nat |awk '{print $6}'|sort|uniq -c|sort -rn
netstat -n | awk '/^tcp/ {++S[$NF]};END {for(a in S) print a, S[a]}'
netstat -anlp|grep 80|grep tcp|awk '{print $5}'|awk -F: '{print $1}'|sort|uniq -c|sort -nr|head -n20
grep -F '<source ' *.xml|awk 'BEGIN{RS="\042"}{print $3}'
ps aux | awk 'NR!=1{a[$1]+=$6;} END { for(i in a) print i ", " a[i]"KB";}'
netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -nr
seq 9 | sed 'H;g' | awk -v RS='' '{for(i=1;i<=NF;i++)printf("%dx%d=%d%s", i, NR, i*NR, i==NR?"\n":"\t")}'
ls | xargs md5sum | sort -u -t" " -k1,1 | awk '{print $2}'|wc -l
grep sysid pharoscontent-temp1951655548413680597.xml|head -1|awk 'BEGIN{FS=" "}{print $3}'|awk 'BEGIN{FS="\042"}{print $2}'|awk 'BEGIN{FS="-"}{print $1}'
awk '$3 > 0' emp.data
awk '$3 > 0{print $1,$2}' emp.data
awk '{print $1, $2*$3}' emp.data
awk '$3 == 0' emp.data
ls -l|awk -f stand.awk
awk '{print}' emp.data
awk '{print NF, $1, $NF}' emp.data
awk '$2 >5' emp.data
awk '/susie/' emp.data
awk 'BEGIN {print "name rate hours";print ""};{print}' emp.data
awk 'BEGIN {print "name rate hours";print ""};' emp.data
awk 'BEGIN {print "name rate hours";print ""};{}' emp.data
awk 'BEGIN {print "name rate hours";print ""};{print $0}' emp.data
awk '$3 > 15{emp = emp +1};END {print emp, "employees worked more than 15 hours"}' emp.data
awk 'END {print NR, "employees"}' emp.data
awk '{pay = pay + $2*$3};END{print NR, "employees", "Total pay is" pay}' emp.data
awk '{pay = pay + $2*$3};END{print NR, "employees", "Total pay is", pay, "average pay is", pay/NR}' emp.data
awk '$2>maxrate{maxrate=$2;maxemp=$1};END{print "highest rate:",maxrate,"for",maxemp}' emp.data
awk '{pay = pay + $2*$3};END{print NR, "employees";print "total pay is", pay;print "average pay is", pay/NR}' emp.data
awk '{names=names $1 " "}END{print names}' emp.data
awk '{last = $0} END {print last}' emp.data
awk '{print $1, length($1), length($0)}' emp.data
awk '{print $0, length($0)}' emp.data
awk '$2 > 6 {n = n+1; pay = pay+$2*$3};END{if(n>0) print n, "employees, total pay is", pay,"average pay is",pay/n;else print "no employee are paid more than $6/hour"}' emp.data
awk '{i=1;while(i<=3){printf("\t%.2f\n",$1*(1+$2)^i);i=i+1}}' 100 .06 5
awk '{i=1;while(i<=$3){printf("\t%.2f\n",$1*(1+$2)^i);i=i+1}}'
awk '{for(i=1;i<=$3;i=i+1)printf("\t%.2f\n",$1*(1+$2)^i)}\'
awk '{for(i=1;i<=$3;i=i+1)printf("\t%.2f\n",$1*(1+$2)^i)}'
awk '{line[NR] = $0}END{for(i=NR;i>0;i--) print line[i]}' emp.data
awk '{print $NF}' emp.data
awk '{field=$NF}END{print field}' emp.data
awk 'NF>4' emp.data
ll|awk '/^d/'
ll|awk '/^-/'
ll|awk '{print $9}'
ll|awk '{print $9}'|grep '[0-9]'|sort -n
ll|awk '{print $9}'|awk -FS. '{print $1}'
ll|awk '{print $9}'|awk -FS"." '{print $1}'
ll|awk '{print $9}'|awk -F. '{print $1}'
ll|awk '{print $9}'|awk -F. '{print $1}'|awk -F_ '{print $1}'
ll|awk '{print $9}'|awk -F. '{print $1}'|awk -F_ '{print $2}'
ll|awk '{print $9}'|awk -F. '{print $1}'|awk -F_ '{print $2}'|sort
ll|awk '{print $9}'|awk -F. '{print $1}'|awk -F_ '{print $2}'|sort -n
ll|awk '{print $9}'|awk -F. '{print $1}'|awk -F_ '{print $2}'|sort -n|less
md5sum *.xml|sort -k1|awk '{if($1==prev) {print $2}; prev=$1}'|xargs rm
history | awk '{CMD[$2]++;count++;}END { for (a in CMD) history'|grep find|grep rm
awk 'BEGIN { srand() } rand() >= 0.5 { print; exit }' random.txt
for i in $(ls); do echo $(stat -c%y $i|awk '{print $1}'); done
for i in $(ls); do mv $i $(stat -c%y $i|awk '{print $1}')-$i; done
echo "for i in $(ls); do mv $i $(stat -c%y $i|awk '{print $1}')-$i; done"
dpkg -l linux-{image,headers}-* | awk '/^ii/{print $2}' | egrep '[0-9]+\.[0-9]+\.[0-9]+' | grep -v $(uname -r) | xargs sudo apt-get -y purge
for i in *.txt; do mv $i $(stat -c%y $i|awk '{print $1}')-$i; done
