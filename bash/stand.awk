#!/bin/awk -f
#Beth 4.00 0
#Dan 3.75 0
#Kathy 4.00 10
#Mark 5.00 20
#Mary 5.50 22
#Susie 4.25 18
BEGIN { print "Name\tRate\tTime" }
{ print $1, "\t", $2,"\t",$3}
END { print " - DONE -" }
