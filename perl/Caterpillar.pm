use strict;
use warnings;

package Caterpillar;

# Inherit from Exporter
use parent ("Exporter");

sub crawl  { print "inch inch";   }
sub eat    { print "chomp chomp"; }
sub pupate { print "bloop bloop"; }

#for exporter and exporter1
#our @EXPORT_OK = ("crawl", "eat");

#for exporter2
our @EXPORT = ("crawl", "eat", "pupate");

return 1;


