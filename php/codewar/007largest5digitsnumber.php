<?php
/*
In the following 6 digit number:

283910
91 is the greatest sequence of 2 digits.

In the following 10 digit number:

1234567890
67890 is the greatest sequence of 5 digits.

Complete the solution so that it returns the largest five digit number found within the number given. The number will be passed in as a string of only digits. It should return a five digit integer. The number passed may be as large as 1000 digits.
 */
//my
function solution(string $s): int {
    // Your code here
    $len = strlen($s) - 4;
    $largest = 0;
    for($i = 0; $i < $len; $i++){
        $number = substr($s, $i, 5);
        if($number >= $largest){
            $largest = $number;
        }
    }
    return $largest;
}
echo solution('1234567890');

//best
function solution(string $s): int {
    if(strlen($s) <= 5) return (int)$s;
    return max((int)substr($s, 0, 5), solution(substr($s, 1)));
}
