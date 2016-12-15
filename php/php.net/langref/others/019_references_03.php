<?php
$ref = 0;
$row =& $ref;
foreach (array(1, 2, 3) as $row) {
    // do something
    echo $row."\n";
}
echo $ref."\n"; // 3 - last element of the iterated array

function foo(&$var)
{
    $var++;
}

$a=5;
foo($a);
echo $a."\n";
