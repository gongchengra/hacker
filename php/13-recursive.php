#!/usr/bin/php
<?php
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
xdebug_start_trace("trace.log");
recursion(20);
xdebug_stop_trace();
echo factorial(20);
