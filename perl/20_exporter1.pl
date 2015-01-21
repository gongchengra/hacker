#!/usr/bin/perl
use strict;
use warnings;
use Caterpillar (); # no subroutines named, no import() call made

# and yet...
Caterpillar::crawl();  # "inch inch"
Caterpillar::eat();    # "chomp chomp"
Caterpillar::pupate(); # "bloop bloop"
