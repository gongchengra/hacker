<?php
$arr = array(
    array(1,2,3,4),
    array(4,5,6,8),
    array(0,3,6,7,9),
    array(4,8,9),
);
function boom($a)
{
    $count_bag = count($a);
    for ($i = 0; $i < $count_bag; $i ++) {
        $walk[$i] = 0;
        $count_ball[$i] = count($a[$i]);
    }
    $max = 0;
    $end = 1;
    $last_one = false;
    while ($end > 0 && $max < 10000) {
        $end = 0;
        $o = '';
        $i = 0;
        foreach ($walk as $k => $v) {
            if (isset($a[$i][$v])) {
                $o .= "{$a[$i][$v]} ";
            } else {
                // Catch计算错误
                echo "<b>boom!! $i $v </b><br />";
            }
            $i ++;
        }
        $walk[0] ++;
        // 进位
        $j = 0;
        foreach ($walk as $kk => $vv) {
            if ($walk[$j] > ($count_ball[$j]-1)) {
                if ($j < $count_bag-1) {
                    $walk[$j] = 0;
                    $walk[$j+1] ++;
                }
            }
            $end += (($count_ball[$j]-1) - $walk[$j]);
            $j ++;
        }
        echo "$o \n";
        $max ++;
    }
}
boom($arr);
