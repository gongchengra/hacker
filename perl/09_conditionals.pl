#!/usr/bin/perl
use strict;
use warnings;

my $word = "antidisestablishmentarianism";
my $strlen = length $word;
if($strlen >= 15) {
    print "'", $word, "' is a very long word";
} elsif(10 <= $strlen && $strlen < 15) {
    print "'", $word, "' is a medium-length word";
} else {
    print "'", $word, "' is a short word";
}
print "\n";
print "'", $word, "' is actually enormous" if $strlen >= 20;
print "\n";

my $temperature = 20;
unless($temperature > 30) {
    print $temperature, " degrees Celsius is not very hot";
} else {
    print $temperature, " degrees Celsius is actually pretty hot";
}
print "\n";
print "Oh no it's too cold" unless $temperature > 15;
print "\n";

my $gain = 48;
print "You gained ", $gain, " ", ($gain == 1 ? "experience point" : "experience points"), "!";
print "\n";

my $lost = 1;
#Do not use
print "You lost ", $lost, " t", ($lost == 1 ? "oo" : "ee"), "th!";
#Use this because others can search tooth in code.
print "You lost ", $lost, ($lost == 1 ? "tooth" : "teeth"), "!";
print "\n";

my $eggs = 5;
print "You have ", $eggs == 0 ? "no eggs" :
$eggs == 1 ? "an egg"  :
"some eggs";
print "\n";

