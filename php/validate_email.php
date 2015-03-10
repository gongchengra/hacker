#!/usr/bin/php
<?php
$f = fopen('php://stdin', 'r');
// Method 1: Use php function filter_var
while ($line = fgets($f)) {
    $validate = filter_var(trim($line), FILTER_VALIDATE_EMAIL);
    if ($validate !== FALSE) {
        echo $validate." is valid email address!\n";
    } else {
        echo trim($line)." is not valid email address.\n";
    }
}

// Method 2: Use Regex Expression:
//
// Basic Version: http://thedailywtf.com/articles/Validating_Email_Addresses
// $regex = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$";
//
// Complex Version: http://thedailywtf.com/articles/Validating_Email_Addresses
//$regex = "/^[-!#$%&'*+\/0-9=?A-Z^_a-z{|}~'](\.?[-!#$%&'*+\/0-9=?A-Z^_a-z{|}~'])*@[a-zA-Z](-?[a-zA-Z0-9])*(\.[a-zA-Z](-?[a-zA-Z0-9])*)+$/";
//while( $line = fgets( $f ) ) {
//    if(preg_match($regex,trim($line),$match)){
//        echo $match[0]." is valid email!\n";
//    } else{
//        echo trim($line)." is not valid email.\n";
//    }
//}

fclose($f);
