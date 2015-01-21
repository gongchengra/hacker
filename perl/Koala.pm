#!/usr/bin/perl
use strict;
use warnings;
package Koala;

# Inherit from Animal
use parent ("Animals");

# Override one method
sub can_eat {
	my $self = shift @_; # Not used. You could just put "shift @_;" here
	my $food = shift @_;
	return $food eq "eucalyptus";
}

return 1;


