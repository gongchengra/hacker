#!/usr/bin/perl
use strict;
use warnings;
my $variables = {
    scalar  =>  {
        description => "single item",
        sigil => '$',
    },
    array   =>  {
        description => "ordered list of items",
        sigil => '@',
    },
    hash    =>  {
        description => "key/value pairs",
        sigil => '%',
    },
};
print "Scalars begin with a $variables->{'scalar'}->{'sigil'}\n";
print "Array begin with a $variables->{'array'}->{'sigil'}\n";
print "Hash begin with a $variables->{'hash'}->{'sigil'}\n";

sub square {
    my $num = shift;
    my $result = $num * $num;
    return $result;
}

print square(9876543210)."\n";
print square(1234567890);
