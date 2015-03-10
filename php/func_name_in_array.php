#!/usr/bin/php
<?php
function foo()
{
    echo "In foo()<br />\n";
}

function bar($arg = 'baby')
{
    echo "In bar(); argument was '$arg'.<br />\n";
}

function echoit($string = 'In echoit')
{
    echo $string;
}

$funcs = array("foo", "bar", "echoit");
foreach ($funcs as $func) {
    $func();
}
