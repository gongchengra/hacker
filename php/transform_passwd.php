#!/usr/bin/php
<?php
if ($argc != 2 || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    echo "Useage: Input a string with only characters and numbers: \n";
    echo "It will return a string which shift upleft on keyboard, so you can use as a passwd. \n";
} else {
    //character map
    $crypt_array['0'] = array(")","_","+");
    $crypt_array['1'] = array("!","@","#");
    $crypt_array['2'] = array("@","#","$");
    $crypt_array['3'] = array("#","$","%");
    $crypt_array['4'] = array("$","%","^");
    $crypt_array['5'] = array("%","^","&");
    $crypt_array['6'] = array("^","&","*");
    $crypt_array['7'] = array("&","*","(");
    $crypt_array['8'] = array("*","(",")");
    $crypt_array['9'] = array("(",")","_");
    $crypt_array['a'] = array("q","w","e","Q","W","E");
    $crypt_array['b'] = array("g","h","j","G","H","J");
    $crypt_array['c'] = array("d","f","g","D","F","G");
    $crypt_array['d'] = array("e","r","t","E","R","T");
    $crypt_array['e'] = array("3","4","5","#","$","%");
    $crypt_array['f'] = array("r","t","y","R","T","Y");
    $crypt_array['g'] = array("t","y","u","T","Y","U");
    $crypt_array['h'] = array("y","u","i","Y","U","I");
    $crypt_array['i'] = array("8","9","0","*","(",")");
    $crypt_array['j'] = array("u","i","o","U","I","O");
    $crypt_array['k'] = array("i","o","p","I","O","P");
    $crypt_array['l'] = array("o","p","[","O","P","{");
    $crypt_array['m'] = array("j","k","l","J","K","L");
    $crypt_array['n'] = array("h","j","k","H","J","K");
    $crypt_array['o'] = array("9","0","-","(",")","0");
    $crypt_array['p'] = array("0","-","=",")","_","+");
    $crypt_array['q'] = array("1","2","3","!","@","#");
    $crypt_array['r'] = array("4","5","6","$","%","^");
    $crypt_array['s'] = array("w","e","r","W","E","R");
    $crypt_array['t'] = array("5","6","7","%","^","&");
    $crypt_array['u'] = array("7","8","9","&","*","(");
    $crypt_array['v'] = array("f","g","h","F","G","H");
    $crypt_array['w'] = array("2","3","4","@","#","$");
    $crypt_array['x'] = array("s","d","f","S","D","F");
    $crypt_array['y'] = array("6","7","8","^","&","*");
    $crypt_array['z'] = array("a","s","d","A","S","D");

    $origin_string = $argv[1];
    $origin_string = preg_replace("/[^0-9a-zA-Z]/", '', $origin_string);
    $origin_string_array = str_split($origin_string);
    $final_string = array();
    foreach ($origin_string_array as $key => $val) {
        if (preg_match("/[A-Z]/", $val)) {
            $index = 3;
            $val = strtolower($val);
        } else {
            $index = 0;
        }
        if ($key > 0) {
            $index += substr_count(substr($origin_string, 0, $key-1), $val);
            if ($origin_string_array[0] == $origin_string_array[1]) {
                $index++;
            }
        }
        $index = $index % 6;
        $final_string[$key] = $crypt_array[$val][$index];
    }
    echo implode($final_string)."\n";
}
