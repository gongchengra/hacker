#!/usr/bin/perl
use strict;
use warnings;
require Animal;

my $animal = {
	"legs"   => 4,
	"colour" => "brown",
};                       # $animal is an ordinary hash reference
print ref $animal;       # "HASH"
print "\n";
bless $animal, "Animal"; # now it is an object of class "Animal"
print ref $animal;       # "Animal"
print "\n";
print "Animal has ", $animal->{"legs"}, " leg(s)";
print "\n";
$animal->eat("insects", "curry", "eucalyptus");


