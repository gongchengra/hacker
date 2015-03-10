#!/usr/bin/perl
use strict;
use warnings;

my $f = "13_another.pl";
my $result = open my $fh, "<", $f;
if(!$result) {
	die "Couldn't open '".$f."' for reading because: ".$!;
}
print 'while(1)'."\n";
while(1) {
    my $line = readline $fh;
    last unless defined $line;
    chomp $line;
    print $line;
}
close $fh;
print "\n";

open(my $fh1, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
print 'eof'."\n";
while(!eof $fh1) {
	my $line = readline $fh1;
    print $line;
}
close $fh1;
print "\n";

open(my $fh2, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
print 'line'."\n";
while(my $line = <$fh2>) {
    print $line;
}
close $fh2;
print "\n";

open(my $fh3, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
print 'fh3'."\n";
while(<$fh3>) {
    print readline $fh3;
}
close $fh3;
print "\n";

my $wf = 'perl.log';
open(my $fhw, ">", $wf) || die "Couldn't open '".$wf."' for writing because: ".$!;
print $fhw "The eagles have left the nest";
close $fhw;
print "\n";

print "what" unless -e "/usr/bin/perl";
print "exist" if -e "/usr/bin/perl";
