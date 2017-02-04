#!/usr/bin/php
<?php
$arr = [9,8,8,7,6,6,6,5,5,5,5,4,4,4,4,4,3,3,3,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1];
$sum = 0;
foreach($arr as $i) {
    $sum += $i;
}
echo 'Sum of Array: '.$sum."\n";

function snakeSort($array, $nGroup) {
    $sortedArray = [];
    $direction = -1;
    foreach($array as $key => $num) {
        if($key % $nGroup == 0) {
            $direction = -$direction;
        }
        if($direction == 1) {
            $i = $key % $nGroup;
            $sortedArray[$i][] = $num;
        } else {
            $i = $nGroup-1-($key % $nGroup);
            $sortedArray[$i][] = $num;
        }
    }
    return $sortedArray;
}

$sortedArray = snakeSort($arr, 5);
foreach($sortedArray as $i => $line) {
    $lineSum = 0;
    foreach($line as $num) {
        $lineSum += $num;
        echo $num.' ';
    }
    echo $lineSum."\n";
}
