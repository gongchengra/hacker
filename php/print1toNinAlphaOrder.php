#!/usr/bin/php
<?php
$array = range(0, $argv[1]);
//$array = array_map('strval',$array);
//natsort($array);
sort($array, SORT_STRING);
//print_r($array);
print implode('', $array);
