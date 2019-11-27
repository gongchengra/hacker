<?php
// return combinations of all subarray.
// like 46|93|cool|cutton
$arr = [
    '尺寸' => ['46', '150', '175'],
    'color' => ['93', '119', '206', '207'],
    'style' => ['cool', 'sexy'],
    'material' => ['cutton', 'flax', 'silk'],
];

function iterateTwoDimensionArray($arr)
{
    $keys = array_keys($arr);
    $total = 1;
    foreach ($arr as $val) {
        $total *= count($val);
    }
    for ($i = 0; $i < $total; ++$i) {
        $t = $i;
        $s = '';
        foreach ($keys as $v) {
            $idx = $t % count($arr[$v]);
            $t = (int) ($t / count($arr[$v]));
            $s .= $arr[$v][$idx].'|';
        }
        $result[] = trim($s, '|');
    }
    return $result;
}
print_r(iterateTwoDimensionArray($arr));

function printarray($arr, $result)
{
    if(count($arr) == 1){
        foreach($arr[array_keys($arr)[0]] as $val){
            $result[] = $val;
        }
        return $result;
    }else{
        $last = array_pop($arr);
        $prev = printarray($arr,$result);
        foreach($prev as $pre){
            foreach($last as $val){
                $result[] = $pre.'|'.$val;
            }
        }
    }
    return $result;
}
print_r(printarray($arr, []));
