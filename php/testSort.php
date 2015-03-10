<?php
if (PHP_SAPI == 'cli') {
    define('EOL', PHP_EOL);
    define('T', "\t");
} else {
    define('EOL', "<br/>");
    define('T', "&nbsp;");
}
error_reporting(E_ALL);

function fillArray($s, $isBigInt = false)
{
    $limit = $s;
    if ($isBigInt) {
        $limit = PHP_INT_MAX;
    }
    $a = array();
    for ($i = 0; $i<$s;$i++) {
        $a[] = rand(1, $limit);
    }

    return $a;
}

function printArray($a, $keys = null, $color = 'red')
{
    if (!is_null($keys)) {
        foreach ($keys as $k) {
            $a[$k] = "<span style='color: ".$color."'>".$a[$k]."</span>";
        }
    }
    echo '[';
    echo implode(', ', $a);
    echo ']'.EOL;
}

function countingSort(&$a)
{
    $k = max($a);
    $c = array();
    $n = count($a);
    for ($i = 0; $i <= $k; $i++) {
        $c[$i] = 0;
    }
    for ($i = 0;$i < $n; $i++) {
        $c[$a[$i]]++;
    }
    printArray($c);
    $b = 0;
    for ($j = 0;$j <= $k; $j++) {
        for ($i = 0; $i < $c[$j]; $i++) {
            $a[$b] = $j;
            $b++;
        }
        printArray($a);
    }
}

function heapSort(&$a)
{
    $n = count($a);
    heapMake($a);
    printArray($a);
    while ($n > 0) {
        list($a[0], $a[$n - 1]) = array($a[$n - 1], $a[0]);
        $n--;
        heapify($a, 0, $n);
    }
}

function heapMake(&$a)
{
    $n = count($a);
    for ($i = ($n - 1); $i >= 0; $i--) {
        heapify($a, $i, $n);
    }
}

function heapify(&$a, $pos, $n)
{
    while (2 * $pos + 1 < $n) {
        $t = 2 * $pos +1;
        if (2 * $pos + 2 < $n && $a[2 * $pos + 2] >= $a[$t]) {
            $t = 2 * $pos + 2;
        }
        if ($a[$pos] < $a[$t]) {
            list($a[$pos], $a[$t]) = array($a[$t], $a[$pos]);
            $pos = $t;
        } else {
            break;
        }
        printArray($a);
    }
}

$testarray = fillArray(6);
printArray($testarray);
//countingSort($testarray);
heapSort($testarray);
printArray($testarray);
