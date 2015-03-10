#!/bin/awk -f
BEGIN { print "Name\tRate\tTime" }
{ print $1, "\t", $2,"\t",$3}
END { print " - DONE -" }
