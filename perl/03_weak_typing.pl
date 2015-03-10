#!/usr/bin/perl
use strict;
use warnings;
my $str1 = "4G";
my $str2 = "4H";

print $str1 .  $str2; # "4G4H"
print $str1 +  $str2; # "8" with two warnings
print $str1 eq $str2; # "" (empty string, i.e. false)
print $str1 == $str2; # "1" with two warnings

# The classic error
print "yes" == "no"; # "1" with two warnings; both values evaluate to 0 when used as numbers

# always using the correct operator in the correct situation. 
# Numerical operators:  <,  >, <=, >=, ==, !=, <=>, +, *
# # String operators:    lt, gt, le, ge, eq, ne, cmp, ., x

