#!/usr/bin/perl
use strict;
use warnings;
my @array = (
    "print",
    "these",
    "strings",
    "out",
    "for",
    "me", # trailing comma is okay
);

print $array[0].' '; # "print"
print $array[1].' '; # "these"
print $array[2].' '; # "strings"
print $array[3].' '; # "out"
print $array[4].' '; # "for"
print $array[5].' '; # "me"
print $array[6]; # returns undef, prints "" and raises a warning
print "\n";

print $array[-1].' '; # "me"
print $array[-2].' '; # "for"
print $array[-3].' '; # "out"
print $array[-4].' '; # "strings"
print $array[-5].' '; # "these"
print $array[-6].' '; # "print"
print $array[-7]; # returns undef, prints "" and raises a warning
print "\n";

print "This array has ".(scalar @array)." elements"; # "This array has 6 elements"
print "\n";
print "The last populated index is ".$#array;       # "The last populated index is 5"
print "\n";

my $string = "world";
print "Hello $string"; # "Hello world"
print "\n";
print "@array";        # "print these strings out for me"
print "\n";
print "Hello \$string"; # "Hello $string"
print "\n";
print 'Hello $string';  # "Hello $string"
print "\n";
print "\@array";        # "@array"
print "\n";
print '@array';         # "@array"
print "\n";
