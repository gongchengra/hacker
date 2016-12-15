#!/usr/bin/php
<?php
/*http://group.jobbole.com/25967/
 * 对于输入 L 和 R， L 和 R 的范围在 1 到 10^20，求从 L 到 R 中包括数字 49 的个数。
 *
 * 例 1：
 * 输入： 1 - 100
 * 输出： 共有 1 个。
 */
// wrong solution from website
function func($n) {
    if($n < 2){
        return 0;
    } else if ($n == 2) {
        return 1;
    } else {
        $result = ($n-1) * (10**($n-2)) - func($n-2);
        return $result;
    }
}
//echo func(3)."\n"; // 20
//echo func(4)."\n"; // 299
//echo func(5)."\n"; // 3980, wrong 
//echo func(6)."\n"; // 49701, wrong 
//echo func(7)."\n"; // 49701, wrong 

// brute force solution, works only for numbers < 10^8, for large numbers the time is unacceptable.
function number49($number) {
    $count = 0;
    for($i = 0; $i<= $number; $i++){
        if(strpos(strval($i), '49') !== false) {
            $count++;
        }
    }
    return $count;
}
//echo number49(1000)."\n"; //20
//echo number49(10000)."\n"; //299
//echo number49(100000)."\n"; //3970
//echo number49(1000000)."\n"; //49401
//echo number49(10000000)."\n"; //590040

// try to find the pattern of all numbers contains '49'
//for($i=0;$i<=9;$i++){
//    for($j=0;$j<=9;$j++){
//        for($k=0;$k<=9;$k++){
//            for($l=0;$l<=9;$l++){
//                echo $i.$j.$k.$l.'49'."\n";
//                echo $i.$j.$k.'49'.$l."\n";
//                echo $i.$j.'49'.$k.$l."\n";
//                echo $i.'49'.$j.$k.$l."\n";
//                echo '49'.$i.$j.$k.$l."\n";
//            }
//        }
//    }
//}

//final solution
if (($argc != 2 && $argc != 3) || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    echo "Useage: Input two integers x, y (x < y < 10^20) it will return numbers from x to y that contains '49'  \n";
    echo "For example, ".$argv[0]." 1 99 will return 1//(only 49 contains '49')\n";
    echo "x is optional with default value of 1, so ".$argv[0]." 999 will return 20 //(the count of 49[0-9], [0-9]49)\n";
} else {
    //var_dump($dp);
    function count49($n) {
        $dp[0]=[0,0,1];
        //$dp[$i][0] $len <= $i && 包含 49 的个数
        //$dp[$i][1] $len = $i && 首位是 9 && 不包含 49 的个数
        //$dp[$i][2] $len <= $i && 不包含 49 的个数
        for($i=1; $i < 22; $i++){
            $dp[$i][0] = 10 * $dp[$i-1][0] + $dp[$i-1][1];
            $dp[$i][1] = $dp[$i-1][2];
            $dp[$i][2] = 10 * $dp[$i-1][2] - $dp[$i-1][1];
            //                    echo $dp[$i][0].' '.$dp[$i][1].' '.$dp[$i][2]."\n";
        }
        //        print_r($dp);
        $aN = strrev(strval($n+1)).'0';
        //        echo $aN."\n";
        $count = 0;
        $contains49 = false;
        $len = strlen(strval($n))-1;
        //        echo $len."\n";
        for($i = $len; $i > 0; $i--){
            $count += $aN[$i] * $dp[$i][0];
            //            echo $count."\n";
            if($contains49) {
                $count += $aN[$i] * $dp[$i][2];
            } else {
                if($aN[$i] > 4) {
                    $count += $dp[$i][1];
                }
                if($aN[$i+1] == 4 && $aN[$i] == 9) {
                    $contains49 = true;
                }
            }
        }
        return $count;
    }
    if($argc == 2) {
        print count49(intval($argv[1]))."\n";
    } else {
        if(intval($argv[1]) > intval($argv[2])) {
            print count49(intval($argv[1])) - count49(intval($argv[2]))+1."\n";
        } else {
            print count49(intval($argv[2])) - count49(intval($argv[1]))+1."\n";
        }
    }
}
