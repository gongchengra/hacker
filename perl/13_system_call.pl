#!/usr/bin/perl
use strict;
use warnings;

my $rc = system "perl", "13_another.pl", "foo", "bar", "baz";
$rc >>= 8;
print $rc; # "37"
print "\n";

#my $text = `perl 13_another.pl foo bar baz`;
my $text = `echo 1..102`;
print $text; # "foobarbaz"
print "\n";
