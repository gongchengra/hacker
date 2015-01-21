#!/usr/bin/perl
use strict;
use warnings;

my @stack = ("Fred", "Eileen", "Denise", "Charlie");
print @stack; # "FredEileenDeniseCharlie"
print "\n";

print pop @stack; # "Charlie"
print @stack;     # "FredEileenDenise"
print "\n";

push @stack, "Bob", "Alice";
print @stack; # "FredEileenDeniseBobAlice"
print "\n";

print shift @stack; # "Fred"
print @stack;       # "EileenDeniseBobAlice"
print "\n";

unshift @stack, "Hank", "Grace";
print @stack; # "HankGraceEileenDeniseBobAlice"
print "\n";

print splice(@stack, 1, 4, "<<<", ">>>"); # "GraceEileenDeniseBob"
print @stack;                             # "Hank<<<>>>Alice"
print "\n";

my @elements = ("Antimony", "Arsenic", "Aluminum", "Selenium");
print @elements;             # "AntimonyArsenicAluminumSelenium"
print "@elements";           # "Antimony Arsenic Aluminum Selenium"
print join(", ", @elements); # "Antimony, Arsenic, Aluminum, Selenium"
print "\n";

print reverse("Hello", "World");        # "WorldHello"
print reverse("HelloWorld");            # "HelloWorld"
print scalar reverse("HelloWorld");     # "dlroWolleH"
print scalar reverse("Hello", "World"); # "dlroWolleH"
print "\n";

my @capitals = ("Baton Rouge", "Indianapolis", "Columbus", "Montgomery", "Helena", "Denver", "Boise");
print join ", ", map { uc $_ } @capitals;
# "BATON ROUGE, INDIANAPOLIS, COLUMBUS, MONTGOMERY, HELENA, DENVER, BOISE"
print "\n";

print join ", ", grep { length $_ == 6 } @capitals;
# "Helena, Denver"
print "\n";

print scalar grep { $_ eq "Columbus" } @capitals; # "1"
print "\n";

my @elevations = (19, 1, 2, 100, 3, 98, 100, 1056);
print join ", ", sort @elevations;
# "1, 100, 100, 1056, 19, 2, 3, 98"
print "\n";

print join ", ", sort { $a cmp $b } @elevations;
# "1, 100, 100, 1056, 19, 2, 3, 98"
print "\n";

print join ", ", sort { $a <=> $b } @elevations;
# "1, 2, 3, 19, 98, 100, 100, 1056"
print "\n";

sub comparator {
	# lots of code...
	# return -1, 0 or 1
    if($a < $b)
    {
        return -1;
    } elsif($a == $b)
    {
        return 0;
    } else
    {
        return 1;
    }
}
print join ", ", sort comparator @elevations;
print "\n";

