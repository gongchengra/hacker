<?php
/*
  Create a function isAlt() that accepts a string as an argument and validates whether the vowels (a, e, i, o, u) and consonants are in alternate order.

  isAlt("amazon")
  true
 isAlt("apple")
  false
  isAlt("banana")
  // true
 */
//my
function isAlt($s){
    $arr = str_split($s);
    $flagArr = [];
    foreach($arr as $k => $v){
        if(in_array($v,['a','e','i','o','u'])){
            $flagArr[$k] = 1;
        }
        else{
            $flagArr[$k] = -1;
        }
    }
    if(count($flagArr) == 1){return true;}
    foreach($flagArr as $k => $v){
        if($k > 0){
            if($v != 0-$flagArr[$k-1]){return false;}
        }
    }
    return true;
}

//best
function isAlt($s){
    return !preg_match('/[aeiou]{2}|[^aeiou]{2}/', $s);
}
