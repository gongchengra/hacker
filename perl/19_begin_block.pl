#!/usr/bin/perl
use strict;
use warnings;
print "This gets printed second\n";
BEGIN {
	print "This gets printed first\n";
}

print "This 'print' statement gets parsed successfully but never executed";

BEGIN {
	print "This also gets printed first";
}

print "This, also, is parsed successfully but never executed";

...because e4h8v3oitv8h4o8gch3o84c3 there is a huge parsing error down here.

if(0) {
	BEGIN {
		print "This will definitely get printed";
	}
	print "Even though this won't";
}



