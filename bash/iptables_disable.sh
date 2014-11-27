IPT="/sbin/iptables"
$IPT --delete-chain
$IPT --flush
$IPT -P INPUT ACCEPT
$IPT -P FORWARD ACCEPT
$IPT -P OUTPUT ACCEPT

