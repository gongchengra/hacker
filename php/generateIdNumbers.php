#!/usr/bin/php
<?php

$areaNumber = file("/home/gongcheng/code/hacker/c/04_T2260_number_only.txt");

/*
 * http://baike.baidu.com/view/1710258.htm
 */
function normalRand($avgNum=0.5, $stdDev=0.1) {
    // 以下为Box-Mueller方法
    $range = 10000000;
    $u = mt_rand(1, $range) / $range;
    $v = mt_rand(1, $range) / $range;
    $s = sqrt(-2 * log($u));
    $x = $s * sin(2 * M_PI * $v);
    //    $y = $s * cos(2 * M_PI * $v);
    return  $avgNum+$x*$stdDev;
}

function howManyIds(){
    $tmp = round(normalRand(3.1,1.5));
    $ids = mt_rand(2,9);
    if($tmp > 1 && $tmp < 9){
        if($tmp == 2 && mt_rand(0,10) < 2){
            $ids = $tmp;
        }
        if($tmp >2)
            $ids = $tmp;
    }
    return $ids;
}

function randArrayElement($array)
{
    return $array[mt_rand(0, count($array) - 1)];
}

function randDate($min_date='1910-01-01', $max_date='Today') {
    /* Gets 2 dates as string, earlier and later date.
     *        Returns date in between them.
     *            */

    $min_epoch = strtotime($min_date);
    $max_epoch = strtotime($max_date);
    $rand_epoch = rand($min_epoch, $max_epoch);

    $mid_epoch = strtotime('1974-01-01');
    $dev_epoch = ($mid_epoch-$min_epoch)/4;

    $tmp_epoch = normalRand($mid_epoch, $dev_epoch);
    if($tmp_epoch > $min_epoch && $tmp_epoch < $max_epoch){
        $rand_epoch = $tmp_epoch;
    }

    return date('Ymd', $rand_epoch);
}

function calculateVerifyNumber($input){
    $inputArr = str_split($input);
    $sum = $inputArr[0]*7+$inputArr[1]*9+$inputArr[2]*10+$inputArr[3]*5+$inputArr[4]*8+
        $inputArr[5]*4+$inputArr[6]*2+$inputArr[7]*1+$inputArr[8]*6+$inputArr[9]*3+
        $inputArr[10]*7+$inputArr[11]*9+$inputArr[12]*10+$inputArr[13]*5
        +$inputArr[14]*8+$inputArr[15]*4+$inputArr[16]*2;
    $mod = $sum % 11;
    if($mod ==0) return 1;
    if($mod ==1) return 0;
    if($mod ==2) return 'X';
    if($mod > 2) return 12-$mod;
}

function generateIdNumber($areaNumber){
    $idNumber ='';
    $idNumber .= trim(randArrayElement($areaNumber));
    $idNumber .= randDate();
    $idNumber .= str_pad(mt_rand(1,999),3,'0',STR_PAD_LEFT);
    $idNumber .= calculateVerifyNumber($idNumber);
    return $idNumber;
}

$fp = fopen('normIds.txt', 'w');
for($i = 0; $i < 10000; $i++){
    $n =howManyIds();
    $idNumbers = '';
    for($j=0;$j<$n;$j++){
        $idNumbers .= generateIdNumber($areaNumber);
        $idNumbers .= ',';
    }
    $idNumbers .= generateIdNumber($areaNumber)."\n";
    fwrite($fp,$idNumbers);
}
fclose($fp);

