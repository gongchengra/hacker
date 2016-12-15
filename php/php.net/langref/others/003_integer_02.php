<?php

$large_number = 2147483647;
var_dump($large_number);                     // int(2147483647)

$large_number = 2147483648;
var_dump($large_number);                     // float(2147483648)

$million = 1000000;
$large_number = 50000 * $million * $million * $million;
var_dump($large_number);                     // float(5.0E+22)
var_dump(PHP_INT_MAX); // int(9223372036854775807)
var_dump(PHP_INT_MAX + 1); // float(9.2233720368548E+18)

for ($i = 1; $i <= (PHP_INT_MAX >> 1); $i = $i << 1) {
    echo $i."\n";
}

for ($i = 1; $i < PHP_INT_MAX; $i = $i * 2) {
    echo $i."\n";
}
