IPT="/sbin/iptables"
$IPT --delete-chain
$IPT --flush
$IPT -P INPUT DROP    #1
$IPT -P FORWARD DROP  #1
$IPT -P OUTPUT DROP   #1
$IPT -A INPUT -m state --state RELATED,ESTABLISHED -j ACCEPT #2
$IPT -A INPUT -p tcp -m tcp --dport 80 -j ACCEPT #3
$IPT -A INPUT -p tcp -m tcp --dport 443 -j ACCEPT #3
$IPT -A INPUT -p tcp -m tcp --dport 22 -j ACCEPT #3
$IPT -A INPUT -p tcp -m tcp --dport 21 -j ACCEPT  #3
$IPT -A INPUT -p tcp -m tcp --dport 873 -j ACCEPT #3
$IPT -A INPUT -p tcp -m tcp --dport 9418 -j ACCEPT #3
$IPT -A INPUT -i lo -j ACCEPT #4
$IPT -A INPUT -p icmp -m icmp --icmp-type 8 -j ACCEPT  #5
$IPT -A INPUT -p icmp -m icmp --icmp-type 11 -j ACCEPT #5
$IPT -A OUTPUT -m state --state RELATED,ESTABLISHED -j ACCEPT #6
$IPT -A OUTPUT -p udp -m udp --dport 53 -j ACCEPT #7
$IPT -A OUTPUT -o lo -j ACCEPT #4
$IPT -A OUTPUT -p tcp -m tcp --dport 80 -j ACCEPT #8
$IPT -A OUTPUT -p tcp -m tcp --dport 443 -j ACCEPT #8
$IPT -A OUTPUT -p tcp -m tcp --dport 22 -j ACCEPT #8
$IPT -A OUTPUT -p tcp -m tcp --dport 25 -j ACCEPT #9
$IPT -A OUTPUT -p tcp -m tcp --dport 9418 -j ACCEPT #3
$IPT -A OUTPUT -p icmp -m icmp --icmp-type 8 -j ACCEPT  #10
$IPT -A OUTPUT -p icmp -m icmp --icmp-type 11 -j ACCEPT #10
