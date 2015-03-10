#!/usr/bin/perl
use strict;
use warnings;

my $string = "Hello world";
if($string =~ m/(\w+)\s+(\w+)/) {
	print "success";
}
print "\n";
print $1; # "Hello"
print "\n";
print $2; # "world"
print "\n";

my $string1 = "colourless green ideas sleep furiously";
my @matches = $string1 =~ m/(\w+)\s+((\w+)\s+(\w+))\s+(\w+)\s+(\w+)/;
print join ", ", map { "'".$_."'" } @matches;
# prints "'colourless', 'green ideas', 'green', 'ideas', 'sleep', 'furiously'"
print "\n";

my $string2 = "Good morning world";
$string2 =~ s/world/Vietnam/;
print $string2; # "Good morning Vietnam"
print "\n";

my $string3 = "a tonne of feathers or a tonne of bricks";
while($string3 =~ m/(\w+)/g) {
  print "'".$1."'\n";
}
my @matches1 = $string3 =~ m/(\w+)/g;
print join ", ", map { "'".$_."'" } @matches1;
print "\n";

# Try once without /g.
$string3 =~ s/[aeiou]/r/;
print $string3; # "r tonne of feathers or a tonne of bricks"
print "\n";

# Once more.
$string3 =~ s/[aeiou]/r/;
print $string3; # "r trnne of feathers or a tonne of bricks"
print "\n";

# And do all the rest using /g
$string3 =~ s/[aeiou]/r/g;
print $string3, "\n"; # "r trnnr rf frrthrrs rr r trnnr rf brrcks"
print "\n";

print "Hello world" =~ m/
  (\w+) # one or more word characters
  [ ]   # single literal space, stored inside a character class
#  (\w+) # literal "world"
#  world # literal "world"
/x;


