#!/usr/local/bin/php
<?php
xdebug_start_trace();
function recursion($a)
{
    if ($a < 21) {
        echo "$a\n";
        recursion($a + 1);
    }
}
function factorial($number) {

    if ($number < 2) {
        return 1;
    } else {
        return ($number * factorial($number-1));
    }
}
recursion(0);
//echo factorial(20);
