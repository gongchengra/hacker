#!/usr/bin/perl
use strict;
use warnings;
my $undef = undef;
print $undef; # prints the empty string "" and raises a warning
# implicit undef:
my $undef2;
print $undef2; # prints "" and raises exactly the same warning
my $num = 4040.5;
print $num; # "4040.5"
my $string = "world";
print $string; # "world"
print "Hello ".$string; # "Hello world"
