<?php
// 数组是用标准比较运算符这样比较的
function standard_array_compare($op1, $op2)
{
    if (count($op1) < count($op2)) {
        return -1; // $op1 < $op2
    } elseif (count($op1) > count($op2)) {
        return 1; // $op1 > $op2
    }
    foreach ($op1 as $key => $val) {
        if (!array_key_exists($key, $op2)) {
            return; // uncomparable
        } elseif ($val < $op2[$key]) {
            return -1;
        } elseif ($val > $op2[$key]) {
            return 1;
        }
    }

    return 0; // $op1 == $op2
}
$arr1 = [1=>'2', '2'=>'3'];
$arr2 = [2=>'2', '3'=>'3'];
print standard_array_compare($arr1, $arr2)."\n";
print $arr1 <=> $arr2;
echo "\n";
// 乍看起来下面的输出是 'true'
echo (true?'true':false?'t':'f');
echo "\n";
// 然而，上面语句的实际输出是't'，因为三元运算符是从左往右计算的
// 下面是与上面等价的语句，但更清晰
echo ((true ? 'true' : 'false') ? 't' : 'f');
