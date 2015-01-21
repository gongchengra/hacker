#!/usr/bin/perl
use strict;
use warnings;

sub hyphenate {
  # Extract the first argument from the array, ignore everything else
  my $word = shift @_;
  # An overly clever list comprehension
  $word = join "-", map { substr $word, $_, 1 } (0 .. (length $word) - 1);
  return $word;
}
print hyphenate("exterminate"); # "e-x-t-e-r-m-i-n-a-t-e"
print "\n";

my $x = 7;
sub reassign {
  $_[0] = 42;
}
reassign($x);
print $x; # "42"
print "\n";

sub left_pad {
	my $oldString = $_[0];
	my $width     = $_[1];
	my $padChar   = $_[2];
	my $newString = ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}
sub left_pad {
	my $oldString = shift @_;
	my $width     = shift @_;
	my $padChar   = shift @_;
	my $newString = ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}
sub left_pad {
	my $oldString = shift;
	my $width     = shift;
	my $padChar   = shift;
	my $newString = ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}
sub left_pad {
	my ($oldString, $width, $padChar) = @_;
	my $newString = ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}
print left_pad("hello", 10, "+"); # "+++++hello"
print "\n";

sub left_pad1 {
	my %args = @_;
	my $newString = ($args{"padChar"} x ($args{"width"} - length $args{"oldString"})) . $args{"oldString"};
	return $newString;
}
print left_pad1("oldString" => "pod", "width" => 10, "padChar" => "+");
print "\n";

sub contextualSubroutine {
	# Caller wants a list. Return a list
	return ("Everest", "K2", "Etna") if wantarray;
	# Caller wants a scalar. Return a scalar
	return 3;
}
my @array = contextualSubroutine();
print @array; # "EverestK2Etna"
print "\n";
my $scalar = contextualSubroutine();
print $scalar; # "3"
print "\n";

