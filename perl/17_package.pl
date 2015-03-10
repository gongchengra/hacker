#!/usr/bin/perl
use strict;
use warnings;
sub subroutine {
	print "universe\n";
}

package Food::Potatoes;

# no collision:
sub subroutine {
	print "kingedward\n";
}

subroutine();                 # "kingedward"
main::subroutine();           # "universe"
Food::Potatoes::subroutine(); # "kingedward"
