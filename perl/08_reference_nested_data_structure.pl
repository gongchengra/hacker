#!/usr/bin/perl
use strict;
use warnings;

#arrays and hashes cannot contain other arrays and hashes as elements. 
my @outer = ("Sun", "Mercury", "Venus", undef, "Mars");
my @inner = ("Earth", "Moon");
$outer[3] = @inner;
print $outer[3]; # "2"
print "\n";

# a scalar variable may contain a reference to any variable, 
# including an array variable or a hash variable.
# This is how more complicated data structures are created in Perl.
#
# A reference is created using a backslash.
my $colour    = "Indigo";
my $scalarRef = \$colour;
print $colour;         # "Indigo"
print "\n";
print $scalarRef;      # e.g. "SCALAR(0x182c180)"
print "\n";
print ${ $scalarRef }; # "Indigo"
print "\n";
#As long as the result is not ambiguous, you can omit the braces too:
print $$scalarRef;
print "\n";

my @colours = ("Red", "Orange", "Yellow", "Green", "Blue");
my $arrayRef = \@colours;
print $colours[0];       # direct array access
print "\n";
print ${ $arrayRef }[0]; # use the reference to get to the array
print "\n";
print $arrayRef->[0];    # exactly the same thing
print "\n";

my %atomicWeights = ("Hydrogen" => 1.008, "Helium" => 4.003, "Manganese" => 54.94);
my $hashRef = \%atomicWeights;
print $atomicWeights{"Helium"}; # direct hash access
print "\n";
print ${ $hashRef }{"Helium"};  # use a reference to get to the hash
print "\n";
print $hashRef->{"Helium"};     # exactly the same thing - this is very common
print "\n";

my %owner1 = (
	"name" => "Santa Claus",
	"DOB"  => "1882-12-25",
);
my %owner2 = (
	"name" => "Mickey Mouse",
	"DOB"  => "1928-11-18",
);

# long
my $owner1Ref = \%owner1;
my $owner2Ref = \%owner2;
my @owners = ( $owner1Ref, $owner2Ref );
my $ownersRef = \@owners;
my %account = (
	"number" => "12345678",
	"opened" => "2000-01-01",
	"owners" => $ownersRef,
);

# short
my @owners = ( \%owner1, \%owner2 );
my %account = (
	"number" => "12345678",
	"opened" => "2000-01-01",
	"owners" => \@owners,
);

# anonymous arrays and hashes using different symbols
# long
# Braces denote an anonymous hash
my $owner1Ref = {
	"name" => "Santa Claus",
	"DOB"  => "1882-12-25",
};
my $owner2Ref = {
	"name" => "Mickey Mouse",
	"DOB"  => "1928-11-18",
};
# Square brackets denote an anonymous array
my $ownersRef = [ $owner1Ref, $owner2Ref ];
my %account = (
	"number" => "12345678",
	"opened" => "2000-01-01",
	"owners" => $ownersRef,
);

# short
my %account = (
	"number" => "31415926",
	"opened" => "3000-01-01",
	"owners" => [
		{
			"name" => "Philip Fry",
			"DOB"  => "1974-08-06",
		},
		{
			"name" => "Hubert Farnsworth",
			"DOB"  => "2841-04-09",
		},
	],
);

#print the information out by reversing the same procedure in each case.
my $ownersRef = $account{"owners"};
my @owners    = @{ $ownersRef };
my $owner1Ref = $owners[0];
my %owner1    = %{ $owner1Ref };
my $owner2Ref = $owners[1];
my %owner2    = %{ $owner2Ref };
print "Account #", $account{"number"}, "\n";
print "Opened on ", $account{"opened"}, "\n";
print "Joint owners:\n";
print "\t", $owner1{"name"}, " (born ", $owner1{"DOB"}, ")\n";
print "\t", $owner2{"name"}, " (born ", $owner2{"DOB"}, ")\n";

#Or, for short:
my @owners = @{ $account{"owners"} };
my %owner1 = %{ $owners[0] };
my %owner2 = %{ $owners[1] };
print "Account #", $account{"number"}, "\n";
print "Opened on ", $account{"opened"}, "\n";
print "Joint owners:\n";
print "\t", $owner1{"name"}, " (born ", $owner1{"DOB"}, ")\n";
print "\t", $owner2{"name"}, " (born ", $owner2{"DOB"}, ")\n";

#Or using references and the -> operator:
my $ownersRef = $account{"owners"};
my $owner1Ref = $ownersRef->[0];
my $owner2Ref = $ownersRef->[1];
print "Account #", $account{"number"}, "\n";
print "Opened on ", $account{"opened"}, "\n";
print "Joint owners:\n";
print "\t", $owner1Ref->{"name"}, " (born ", $owner1Ref->{"DOB"}, ")\n";
print "\t", $owner2Ref->{"name"}, " (born ", $owner2Ref->{"DOB"}, ")\n";

#And if we completely skip all the intermediate values:
print "Account #", $account{"number"}, "\n";
print "Opened on ", $account{"opened"}, "\n";
print "Joint owners:\n";
print "\t", $account{"owners"}->[0]->{"name"}, " (born ", $account{"owners"}->[0]->{"DOB"}, ")\n";
print "\t", $account{"owners"}->[1]->{"name"}, " (born ", $account{"owners"}->[1]->{"DOB"}, ")\n";

#This array has five elements:
my @array1 = (1, 2, 3, 4, 5);
print @array1; # "12345"
print "\n";

#This array, however, has ONE element 
#(which happens to be a reference to an anonymous, five-element array):
my @array2 = [1, 2, 3, 4, 5];
print @array2; # e.g. "ARRAY(0x182c180)"
print "\n";

#This scalar is a reference to an anonymous, five-element array:
my $array3Ref = [1, 2, 3, 4, 5];
print $array3Ref;      # e.g. "ARRAY(0x22710c0)"
print "\n";
print @{ $array3Ref }; # "12345"
print "\n";
print @$array3Ref;     # "12345"
print "\n";
