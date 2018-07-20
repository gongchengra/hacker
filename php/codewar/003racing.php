<?php
/*
Two tortoises named A and B must run a race. A starts with an average speed of 720 feet per hour. Young B knows she runs faster than A, and furthermore has not finished her cabbage.

When she starts, at last, she can see that A has a 70 feet lead but B's speed is 850 feet per hour. How long will it take B to catch A?

More generally: given two speeds v1 (A's speed, integer > 0) and v2 (B's speed, integer > 0) and a lead g (integer > 0) how long will it take B to catch A?

The result will be an array [hour, min, sec] which is the time needed in hours, minutes and seconds (don't worry for fractions of second).

If v1 >= v2 then return nil, nothing, null, None or {-1, -1, -1} for C++, C, Go, Nim, [] for Kotlin.

    Examples
    race(720, 850, 70) => [0, 32, 18]
    race(80, 91, 37)   => [3, 21, 49]
 */
//my
function race($v1, $v2, $g) {
    // your code
    if($v1 >= $v2) { return [];}
    $h = intval($g/($v2-$v1));
    $m = intval(60*$g/($v2-$v1)-$h*60);
    $s = intval(3600*$g/($v2-$v1)-$h*3600-$m*60);
    return [$h, $m, $s];
}

var_dump(race(720, 850, 70));
var_dump(race(1, 4, 55));
//best
function race($v1, $v2, $g) {
    if($v1 >= $v2) return null;
    $h = $g / ($v2 - $v1);
    return [floor($h), (floor($h * 60) % 60), floor($h * 3600) % 60];
}
