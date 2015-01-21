#!/usr/bin/perl
use strict;
use warnings;
use CGI;
my $cgi = CGI->new;
print $cgi->header(),
$cgi->start_html(),
$cgi->p("Hello World"),
$cgi->end_html();

