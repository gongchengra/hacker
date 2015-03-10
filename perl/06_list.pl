#!/usr/bin/perl
use strict;
use warnings;
#Remember that => is just , in disguise and then look at this example:
#
#("one", 1, "three", 3, "five", 5)
#is equal to 
#("one" => 1, "three" => 3, "five" => 5)

# List values cannot be nested.
my @array = (
    "apples",
    "bananas",
    (
        "inner",
        "list",
        "several",
        "entries",
    ),
    "cherries",
);

print $array[0].' '."\n"; # "apples"
print $array[1].' '."\n"; # "bananas"
print $array[2].' '."\n"; # "inner"
print $array[3].' '."\n"; # "list"
print $array[4].' '."\n"; # "several"
print $array[5].' '."\n"; # "entries"
print $array[6].' '."\n"; # "cherries"

my %hash = (
    "beer" => "good",
    "bananas" => (
        "green"  => "wait",
        "yellow" => "eat",
    ),
);

# The above raises a warning because the hash was declared using a 7-element list

print $hash{"beer"}.' ';    # "good"
print "\n";
print $hash{"bananas"}.' '; # "green"
print "\n";
print $hash{"wait"}.' ';    # "yellow";
print "\n";
print $hash{"eat"}.' ';     # undef, so prints "" and raises a warning
print "\n";

my @bones   = ("humerus", ("jaw", "skull"), "tibia");
my @fingers = ("thumb", "index", "middle", "ring", "little");
my @parts   = (@bones, @fingers, ("foot", "toes"), "eyeball", "knuckle");
print @parts;

