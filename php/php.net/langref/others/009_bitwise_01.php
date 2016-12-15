<?php
/*
$a & $b And（按位与）   将把 $a 和 $b 中都为 1 的位设为 1。
$a | $b Or（按位或）    将把 $a 和 $b 中任何一个为 1 的位设为 1。
$a ^ $b Xor（按位异或） 将把 $a 和 $b 中一个为 1 另一个为 0 的位设为 1。
~ $a    Not（按位取反） 将 $a 中为 0 的位设为 1，反之亦然。
$a << $b    Shift left（左移）  将 $a 中的位向左移动 $b 次（每一次移动都表示“乘以 2”）。
$a >> $b    Shift right（右移） 将 $a 中的位向右移动 $b 次（每一次移动都表示“除以 2”）。
/*
 * Ignore the top section,
 * it is just formatting to make output clearer.
 */

$format = '(%1$2d = %1$04b) = (%2$2d = %2$04b)'.' %3$s (%4$2d = %4$04b)'."\n";

echo <<<EOH
 ---------     ---------  -- ---------
 result        value      op test
 ---------     ---------  -- ---------
EOH;

/*
 * Here are the examples.
 */

$values = array(0, 1, 2, 4, 8);
$test = 1 + 4;

echo "\n Bitwise AND \n";
foreach ($values as $value) {
    $result = $value & $test;
    printf($format, $result, $value, '&', $test);
}

echo "\n Bitwise Inclusive OR \n";
foreach ($values as $value) {
    $result = $value | $test;
    printf($format, $result, $value, '|', $test);
}

echo "\n Bitwise Exclusive OR (XOR) \n";
foreach ($values as $value) {
    $result = $value ^ $test;
    printf($format, $result, $value, '^', $test);
}

function isPower2($n)
{
    if ($n & $n - 1) {
        return false;
    } else {
        return true;
    }
}

for ($i = 0; $i <= 80; ++$i) {
    if (isPower2($i)) {
        echo $i."\n";
    }
}

echo 12 ^ 9; // Outputs '5'

echo '12' ^ '9'; // Outputs the Backspace character (ascii 8)
// ('1' (ascii 49)) ^ ('9' (ascii 57)) = #8

echo 'hallo' ^ 'hello'; // Outputs the ascii values #0 #4 #0 #0 #0
// 'a' ^ 'e' = #4

echo 2 ^ '3'; // Outputs 1
// 2 ^ ((int)"3") == 1

echo '2' ^ 3; // Outputs 1
// ((int)"2") ^ 3 == 1

