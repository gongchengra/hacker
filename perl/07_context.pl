#!/usr/bin/perl
use strict;
use warnings;
my $scalar = "Mendeleev";
my @array = ("Alpha", "Beta", "Gamma", "Pie");
my %hash = ("Alpha" => "Beta", "Gamma" => "Pie");

#A scalar expression evaluated in list context is silently converted into a single-element list:
my @array1 = "Mendeleev"; # same as 'my @array = ("Mendeleev");'

#An array expression evaluated in scalar context returns the length of the array:
my $scalar1 = @array;
print $scalar1; # "4"
print "\n";

#A list expression (a list is different from an array, remember?) evaluated in scalar
#context returns not the length of the list but the final scalar in the list:

my $scalar2 = ("Alpha", "Beta", "Gamma", "Pie");
print $scalar2; # "Pie"
print "\n";

#The print built-in function evaluates all of its arguments in list context.
my @array1 = ("Alpha", "Beta", "Goo");
my $scalar3 = "-X-";
print @array1;              # "AlphaBetaGoo";
print "\n";
print $scalar3, @array1, 98; # "-X-AlphaBetaGoo98";
print "\n";

#In list context, reverse treats its arguments as a list, and reverses the list.
#In scalar context, reverse concatenates the whole list together and then reverses it as a single word.
print reverse "hello world"; # "hello world"
print "\n";

my $string = reverse "hello world";
print $string; # "dlrow olleh"
print "\n";

#You can force any expression to be evaluated in scalar context using the scalar built-in function:
print scalar reverse "hello world"; # "dlrow olleh"

