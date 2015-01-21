#!/usr/bin/perl
use strict;
use warnings;
my %scientists = (
    "Newton"   => "Isaac",
    "Einstein" => "Albert",
    "Darwin"   => "Charles",
);
print $scientists{"Newton"}.' ';   # "Isaac"
print $scientists{"Einstein"}.' '; # "Albert"
print $scientists{"Darwin"}.' ';   # "Charles"
print $scientists{"Dyson"}.' ';    # returns undef, prints "" and raises a warning
print "\n";

my @scientists = %scientists;
print "@scientists"; # something like "Einstein Albert Darwin Charles Newton Isaac"

my $data = "orange";
my @data = ("purple");
my %data = ( "0" => "blue");

print $data;      # "orange"
print $data[0];   # "purple"
print $data["0"]; # "purple"
print $data{0};   # "blue"
print $data{"0"}; # "blue"
