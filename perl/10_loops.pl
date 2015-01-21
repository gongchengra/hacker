#!/usr/bin/perl
use strict;
use warnings;
print "\n";
my @array = (
    "print",
    "these",
    "strings",
    "out",
    "for",
    "me", # trailing comma is okay
);
my $i = 0;
until($i >= scalar @array) {
	print $i, ": ", $array[$i], ' ';
	$i++;
}
print "\n";

$i = 0;
while($i < scalar @array) {
	print $i, ": ", $array[$i], ' ';
	$i++;
}
print "\n";

$i = 0;
do {
	print $i, ": ", $array[$i], ' ';
	$i++;
} while ($i < scalar @array);
print "\n";

$i = 0;
do {
	print $i, ": ", $array[$i], ' ';
	$i++;
} until ($i >= scalar @array);
print "\n";

for(my $i = 0; $i < scalar @array; $i++) {
	print $i, ": ", $array[$i], ' ';
}
print "\n";

foreach my $string ( @array ) {
	print $string, ' ';
}
print "\n";

foreach my $i ( 0 .. $#array ) {
	print $i, ": ", $array[$i], ' ';
}
print "\n";

my %scientists = (
    "Newton"   => "Isaac",
    "Einstein" => "Albert",
    "Darwin"   => "Charles",
);
foreach my $key (keys %scientists) {
	print $key, ": ", $scientists{$key}, ' ';
}
print "\n";

foreach my $key (sort keys %scientists) {
	print $key, ": ", $scientists{$key}, ' ';
}
print "\n";

foreach ( @array ) {
	print $_,' ';
}
print "\n";

print $_,' ' foreach @array;
print "\n";

CANDIDATE: for my $candidate ( 2 .. 100 ) {
    for my $divisor ( 2 .. sqrt $candidate ) {
        next CANDIDATE if $candidate % $divisor == 0;
    }
    print $candidate." is prime\n";
}
