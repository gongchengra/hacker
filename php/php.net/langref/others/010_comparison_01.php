<?php

var_dump(0 == 'a'); // 0 == 0 -> true
var_dump('1' == '01'); // 1 == 1 -> true
var_dump('10' == '1e1'); // 10 == 10 -> true
var_dump(100 == '1e2'); // 100 == 100 -> true

switch ('a') {
case 0:
    echo '0'."\n";
    break;
case 'a': // never reached because "a" is already matched with 0
    echo 'a';
    break;
}
// Integers
echo "\n".'echo 1 <=> 1'."\n"; // 0
echo 1 <=> 1; // 0
echo "\n".'echo 1 <=> 2'."\n"; // -1
echo 1 <=> 2; // -1
echo "\n".'echo 2 <=> 1'."\n"; // 1
echo 2 <=> 1; // 1

// Floats
echo "\n".'echo 1.5 <=> 1.5'."\n"; // 0
echo 1.5 <=> 1.5; // 0
echo "\n".'echo 1.5 <=> 2.5'."\n"; // -1
echo 1.5 <=> 2.5; // -1
echo "\n".'echo 2.5 <=> 1.5'."\n"; // 1
echo 2.5 <=> 1.5; // 1

// Strings
echo "\n".'echo "a" <=> "a"'."\n"; // 0
echo "a" <=> "a"; // 0
echo "\n".'echo "a" <=> "b"'."\n"; // -1
echo "a" <=> "b"; // -1
echo "\n".'echo "b" <=> "a"'."\n"; // 1
echo "b" <=> "a"; // 1

echo "\n".'echo "a" <=> "aa"'."\n"; // -1
echo "a" <=> "aa"; // -1
echo "\n".'echo "zz" <=> "aa"'."\n"; // 1
echo "zz" <=> "aa"; // 1

// Arrays
echo "\n".'echo [] <=> []'."\n"; // 0
echo [] <=> []; // 0
echo "\n".'echo [1, 2, 3] <=> [1, 2, 3]'."\n"; // 0
echo [1, 2, 3] <=> [1, 2, 3]; // 0
echo "\n".'echo [1, 2, 3] <=> []'."\n"; // 1
echo [1, 2, 3] <=> []; // 1
echo "\n".'echo [1, 2, 3] <=> [1, 2, 1]'."\n"; // 1
echo [1, 2, 3] <=> [1, 2, 1]; // 1
echo "\n".'echo [1, 2, 3] <=> [1, 2, 4]'."\n"; // -1
echo [1, 2, 3] <=> [1, 2, 4]; // -1

// Objects
echo "\n".'$a = (object) ["a" => "b"]'."\n";
$a = (object) ["a" => "b"];
echo '$b = (object) ["a" => "b"]'."\n";
$b = (object) ["a" => "b"];
echo 'echo $a <=> $b'."\n"; // 0
echo $a <=> $b; // 0

echo "\n".'$a = (object) ["a" => "b"]'."\n";
$a = (object) ["a" => "b"];
echo '$b = (object) ["a" => "c"]'."\n";
$b = (object) ["a" => "c"];
echo 'echo $a <=> $b'."\n"; // -1
echo $a <=> $b; // -1

echo "\n".'$a = (object) ["a" => "c"]'."\n";
$a = (object) ["a" => "c"];
echo '$b = (object) ["a" => "b"]'."\n";
$b = (object) ["a" => "b"];
echo 'echo $a <=> $b'."\n"; // 1
echo $a <=> $b; // 1

echo "\n".'$a = (object) ["a" => "b"]'."\n";
$a = (object) ["a" => "b"];
echo '$b = (object) ["b" => "b"]'."\n";
$b = (object) ["b" => "b"];
echo 'echo $a <=> $b'."\n"; // 1
echo $a <=> $b; // 1

