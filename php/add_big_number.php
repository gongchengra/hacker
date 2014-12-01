#!/usr/bin/php
<?php
$a = '2344432438087723480238493284';
$b = '9978787887877878842343538458';

echo big_add($a, $b);
echo "\n";

function big_add($a, $b)
{
    $len = max(strlen($a), strlen($b));
    $num1 = str_pad($a, $len, '0', STR_PAD_LEFT);
    $num2 = str_pad($b, $len, '0', STR_PAD_LEFT);
    $output = array();
    for ($i = $len - 1; $i >= 0; $i --) {
        $sum = (int) $num1{$i}
        + (int) $num2{$i};
        if (isset($output[$i])) {
            $sum += $output[$i];
        }
        $output[$i] = $sum % 10;
        if ($sum > 9) {
            $output[$i - 1] = 1;
        }
    }
    ksort($output);

    return implode($output);
}
