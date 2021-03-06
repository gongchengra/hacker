<?php

$arr = [1, 3, 3, 5, 8, 0, 9, 2, 2, 7, 1, 13, 35, 80, 92, 27, 1];
//$arr = [6, 5, 4, 3, 2, 1, 0, -1];
//$arr = [6, 5, 4, 3, 2, 1];
//$arr = [1, 2, 3, 4, 5, 6, 7];
print_r($arr);

// 计数排序
function CountingSort($arr)
{
    $max = max($arr);
    $countingArr = array();
    $length = count($arr);
    for ($i = 0; $i <= $max; ++$i) {
        $countingArr[$i] = 0;
    }
    for ($i = 0;$i < $length; ++$i) {
        ++$countingArr[$arr[$i]];
    }
    $b = 0;
    for ($j = 0;$j <= $max; ++$j) {
        if ($countingArr[$j] > 0) {
            for ($i = 0; $i < $countingArr[$j]; ++$i) {
                $sortedArr[$b] = $j;
                ++$b;
            }
        }
    }

    return $sortedArr;
}

//print_r(countingSort($arr));

function HeapSort($arr)
{
    $n = count($arr);
    while ($n > 0) {
        $arr = heapify($arr, 0, $n);
        list($arr[0], $arr[$n - 1]) = array($arr[$n - 1], $arr[0]);
        --$n;
    }

    return $arr;
}

function heapify($arr, $pos, $n)
{
    for ($pos = intval($n / 2) - 1;$pos >= 0;--$pos) {
        $lchild = 2 * $pos + 1;
        $rchild = 2 * $pos + 2;
        if ($rchild < $n && $arr[$lchild] < $arr[$rchild]) {
            if ($arr[$pos] < $arr[$rchild]) {
                list($arr[$pos], $arr[$rchild]) = array($arr[$rchild], $arr[$pos]);
            }
        } else {
            if ($arr[$pos] < $arr[$lchild]) {
                list($arr[$pos], $arr[$lchild]) = array($arr[$lchild], $arr[$pos]);
            }
        }
    }

    return $arr;
}

//print_r(HeapSort($arr));

function ShellSort($arr)
{
    $length = count($arr);
    for ($gap = $length >> 1; $gap > 0; $gap >>= 1) {
        for ($i = $gap; $i < $length; ++$i) {
            for ($j = $i - $gap; $j >= 0; $j -= $gap) {
                echo $gap.' '.$i.' '.$j.' '.($j + $gap)."\n";
                if ($arr[$j] > $arr[$j + $gap]) {
                    list($arr[$j], $arr[$j + $gap]) = arr($arr[$j + $gap], $arr[$j]);
                }
            }
        }
    }

    return $arr;
}

//print_r(ShellSort($arr));

// 冒泡排序
function BubbleSort($arr)
{
    // 获得数组总长度
    $num = count($arr);
    // 正向遍历数组
    for ($i = 1; $i < $num; ++$i) {
        // 反向遍历
        for ($j = $num - 1; $j >= $i; --$j) {
            // 相邻两个数比较
            if ($arr[$j] < $arr[$j - 1]) {
                // 暂存较小的数
                $iTemp = $arr[$j - 1];
                // 把较大的放前面
                $arr[$j - 1] = $arr[$j];
                // 较小的放后面
                $arr[$j] = $iTemp;
            }
        }
    }

    return $arr;
}

// 交换法排序
function ExchangeSort($arr)
{
    $num = count($arr);
    // 遍历数组
    for ($i = 0;$i < $num - 1; ++$i) {
        // 获得当前索引的下一个索引
        for ($j = $i + 1; $j < $num; ++$j) {
            // 比较相邻两个的值大小
            if ($arr[$j] < $arr[$i]) {
                // 暂存较小的数
                $iTemp = $arr[$i];
                // 把较大的放前面
                $arr[$i] = $arr[$j];
                // 较小的放后面
                $arr[$j] = $iTemp;
            }
        }
    }

    return $arr;
}

// 选择法排序
function SelectSort($arr)
{
    // 获得数组总长度
    $num = count($arr);
    // 遍历数组
    for ($i = 0;$i < $num - 1; ++$i) {
        // 暂存当前值
        $iTemp = $arr[$i];
        // 暂存当前位置
        $iPos = $i;
        // 遍历当前位置以后的数据
        for ($j = $i + 1;$j < $num; ++$j) {
            // 如果有小于当前值的
            if ($arr[$j] < $iTemp) {
                // 暂存最小值
                $iTemp = $arr[$j];
                // 暂存位置
                $iPos = $j;
            }
        }
        // 把当前值放到算好的位置
        $arr[$iPos] = $arr[$i];
        // 把当前值换成算好的值
        $arr[$i] = $iTemp;
    }

    return $arr;
}

// 插入法排序
function InsertSort($arr)
{
    $num = count($arr);
    // 遍历数组
    for ($i = 1;$i < $num; ++$i) {
        // 获得当前值
        $iTemp = $arr[$i];
        // 获得当前值的前一个位置
        $iPos = $i - 1;
        // 如果当前值小于前一个值切未到数组开始位置
        while (($iPos >= 0) && ($iTemp < $arr[$iPos])) {
            // 把前一个的值往后放一位
            $arr[$iPos + 1] = $arr[$iPos];
            // 位置递减
            --$iPos;
        }
        $arr[$iPos + 1] = $iTemp;
    }

    return $arr;
}

// 快速排序
function QuickSort($arr)
{
    $num = count($arr);
    $l = $r = 0;
    // 从索引的第二个开始遍历数组
    for ($i = 1;$i < $num; ++$i) {
        // 如果值小于索引1
        if ($arr[$i] < $arr[0]) {
            // 装入左索引数组(小于索引1的数据)
            $left[] = $arr[$i];
            ++$l;
        } else {
            // 否则装入右索引中(大于索引1的数据)
            $right[] = $arr[$i];
            ++$r; //
        }
    }
    // 如果左索引有值 则对左索引排序
    if ($l > 1) {
        $left = QuickSort($left);
    }
    // 排序后的数组
    $new_arr = $left;
    // 将当前数组第一个放到最后
    $new_arr[] = $arr[0];
    // 如果又索引有值 则对右索引排序
    if ($r > 1) {
        $right = QuickSort($right);
    }
    // 根据右索引的长度再次增加数据
    for ($i = 0;$i < $r; ++$i) {
        $new_arr[] = $right[$i];
    }

    return $new_arr;
}
