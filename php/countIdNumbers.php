#!/usr/bin/php
<?php

function createDateRangeArray($strDateFrom,$strDateTo)
{
    // takes two dates formatted as YYYY-MM-DD and creates an
    // inclusive array of the dates between the from and to dates.

    $aryRange=array();

    $iDateFrom=mktime(1,0,0,substr($strDateFrom,5,2),     substr($strDateFrom,8,2),substr($strDateFrom,0,4));
    $iDateTo=mktime(1,0,0,substr($strDateTo,5,2),     substr($strDateTo,8,2),substr($strDateTo,0,4));

    if ($iDateTo>=$iDateFrom)
    {
        array_push($aryRange,date('Ymd',$iDateFrom)); // first entry
        while ($iDateFrom<$iDateTo)
        {
            $iDateFrom+=86400; // add 24 hours
            array_push($aryRange,date('Ymd',$iDateFrom));
        }
    }
    return $aryRange;
}

$all = array();
foreach(createDateRangeArray('1910-01-01','2014-08-27') as $key) {
    $all[$key] = 0;
}

$fp = fopen('normIds.txt', 'r') or die("Unable to open file!");
while(!feof($fp)) {
    $idNumbers = explode(',',trim(fgets($fp)));
    foreach($idNumbers as $idNumber) {
        if($idNumber != ''){
            $all[substr($idNumber,6,8)]++;
        }
    }
}
fclose($fp);

$maxKey = 0;
$maxVal = 0;
foreach($all as $key=>$val) {
    echo $key.' '.$val."\n";
    if($val > $maxVal){
        $maxKey = $key;
        $maxVal = $val;
    }
}
echo $maxKey.' '.$maxVal."\n";
echo max($all);
?>
