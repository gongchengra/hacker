#!/usr/bin/perl
use strict;
use warnings;
require Animals;

my $animal = Animals->new();
print ref $animal;       # "HASH"
print "\n";
print "Animals has ", $animal->{"legs"}, " leg(s)";
print "\n";

