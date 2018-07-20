<?php
/*
Create a function named divisors/Divisors that takes an integer and returns an array with all of the integer's divisors(except for 1 and the number itself). If the number is prime return the string '(integer) is prime' (null in C#) (use Either String a in Haskell and Result<Vec<u32>, String> in Rust).

Example:
divisors(12); // => [2, 3, 4, 6]
divisors(25); // => [5]
divisors(13); // => '13 is prime'
 */
//my
function divisors($integer) {
    // Your code here
    $array = [];
    for($i = 2; $i <= sqrt($integer); $i++) {
        if($integer %$i == 0) {
            $array[] = $i;
            if(!in_array($integer/$i,$array)){
                $array[] = $integer/$i;
            }
        }
    }
    if(empty($array)){
        return $integer.' is prime';
    } else{
        sort($array);
        return $array;
    }
}
print_r( divisors(81));

//best
function divisors($integer) {
    $divisors = [];
    for($i = 2; $i < $integer; $i++){
        if(!($integer % $i)){
            $divisors[] = $i;
        }
    }
    return $divisors ?: $integer . ' is prime';
}
