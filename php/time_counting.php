#!/usr/bin/php
<?php
function printhelp($argv)
{
    echo "Useage: Count action and time of a given year from an action time log.\n";
    echo "The Log should have the following format.\n";
    echo "Action.' 'time分the End Time of Action.\n";
    echo "For example, my log on 2017-01-01 is:.\n";
    echo "------------------------------------------------------------.\n";
    echo "2017-01-01.\n";
    echo "起床洗漱 30分0930-1000.\n";
    echo "休息2大食堂午饭 90分1130.\n";
    echo "淘宝店 150分1400.\n";
    echo "午睡 60分1500.\n";
    echo "ooxx 30分1530.\n";
    echo "淘宝店 120分1730.\n";
    echo "2爸妈晚饭 90分1900.\n";
    echo "休息陪儿子洗澡 90分2030.\n";
    echo "微信读书陪儿子 90分2200.\n";
    echo "哄儿子睡觉 30分2230.\n";
    echo "------------------------------------------------------------.\n";
    echo "The log should be recorded in filename format of YYYYMM.txt.\n";
    echo $argv[0]." -year 2016 will count the actions in 2016.\n";
    echo "The result will be given in the file 2016.txt ordered by time spended in reverse order.\n";
    echo $argv[0]." -year 2016 -action hft will count the time of action hft in 2016\n";
    echo $argv[0]." -year 2016 -sleep will count the sleeping time in 2016\n";
    echo $argv[0]." -file 201601.txt will count the actions in January 2016.\n";
    echo "The result will be given in the file action.201601.txt ordered by time spended in reverse order.\n";
    echo $argv[0]." -file 201601.txt -action hft will count the time of action hft in January 2016\n";
    echo $argv[0]." -file 201601.txt -sleep will count the sleeping time in January 2016\n";
}

function file2array($sFilename, $aLines = [])
{
    if (file_exists($sFilename)) {
        $aFile = file($sFilename);
        foreach ($aFile as $iLine => $sLine) {
            if (preg_match('/\d+分\d+/', $sLine, $aMatch) > 0) {
                $aLines[] = trim($sLine);
            }
        }
    }

    return $aLines;
}

function reduceAction($aLines, $aActionTime = [])
{
    foreach ($aLines as $sLine) {
        if (preg_match('/\d+分\d+/', $sLine, $aMatch) > 0) {
            $sAction = explode(' ', $sLine)[0];
            $iTime = explode('分', $aMatch[0])[0];
            if (array_key_exists(strtolower($sAction), $aActionTime)) {
                $aActionTime[strtolower($sAction)] += $iTime;
            } else {
                $aActionTime[strtolower($sAction)] = $iTime;
            }
        }
    }

    return $aActionTime;
}

function calculateActionTime($year)
{
    $aActionTime = [];
    for ($i = 1; $i <= 12; ++$i) {
        $sFilename = $year.str_pad($i, 2, '0', STR_PAD_LEFT).'.txt';
        $aActionTime = reduceAction(file2array($sFilename, []), $aActionTime);
    }

    return $aActionTime;
}

function combineLines($year)
{
    $aLines = [];
    for ($i = 1; $i <= 12; ++$i) {
        $sFilename = $year.str_pad($i, 2, '0', STR_PAD_LEFT).'.txt';
        $aLines = file2array($sFilename, $aLines);
    }

    return $aLines;
}

function countSleepingTime($aLines)
{
    $iSleepingTime = 0;
    foreach ($aLines as $key => $val) {
        if ($key == 0) {
            preg_match('/\d+分\d+/', $val, $aMatch);
            $sWakeupTime = explode('分', $aMatch[0])[1];
            $aWakeupTime = str_split($sWakeupTime, 2);
            $iSleepingTime += $aWakeupTime[0] * 60 + $aWakeupTime[1];
        } else {
            if (strpos($val, '起床') === 0) {
                preg_match('/\d+分\d+/', $val, $aMatch);
                $sWakeupTime = explode('分', $aMatch[0])[1];
                $aWakeupTime = str_split($sWakeupTime, 2);
                $iSleepingTime += $aWakeupTime[0] * 60 + $aWakeupTime[1];
                preg_match('/\d+分\d+/', $aLines[$key - 1], $aMatch);
                $sSleepingTime = explode('分', $aMatch[0])[1];
                $aSleepingTime = str_split($sSleepingTime, 2);
                if ($aSleepingTime[0] < 12) {
                    $iSleepingTime -= $aSleepingTime[0] * 60 + $aSleepingTime[1];
                } else {
                    $iSleepingTime += (24 * 60 - $aSleepingTime[0] * 60 - $aSleepingTime[1]);
                }
            }
        }
    }

    return $iSleepingTime;
}

function searchAction($aActionTime, $sSearchAction)
{
    $iSumTime = 0;
    foreach ($aActionTime as $sAction => $iTime) {
        if (strpos($sAction, $sSearchAction) !== false) {
            echo $sAction.' '.$iTime."\n";
            $iSumTime += $iTime;
        }
    }

    return $sSearchAction.' '.$iSumTime;
}

function array2string($array)
{
    $string = '';
    foreach ($array as $key => $val) {
        $string .= trim($key).' '.$val."\n";
    }

    return $string;
}

if ($argc < 2 || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    printhelp($argv);
} else {
    if ($argv[1] == '-year') {
        $year = $argv[2];
        if ($argc > 3) {
            if ($argv[3] == '-action') {
                $sSearchAction = $argv[4];
                $aActionTime = calculateActionTime($year);
                echo searchAction($aActionTime, $sSearchAction)."\n";
            }
            if ($argv[3] == '-sleep') {
                $aLines = combineLines($year);
                echo countSleepingTime($aLines);
            }
        } else {
            $aActionTime = calculateActionTime($year);
            arsort($aActionTime);
            $sResultFilename = $year.'.txt';
            file_put_contents($sResultFilename, array2string($aActionTime));
        }
    }
    if ($argv[1] == '-file') {
        $sFilename = $argv[2];
        if ($argc > 3) {
            if ($argv[3] == '-action') {
                $sSearchAction = $argv[4];
                $aActionTime = reduceAction(file2array($sFilename, []), []);
                echo searchAction($aActionTime, $sSearchAction)."\n";
            }
            if ($argv[3] == '-sleep') {
                $aLines = file2array($sFilename, []);
                echo countSleepingTime($aLines);
            }
        } else {
            $aActionTime = reduceAction(file2array($sFilename, []), []);
            arsort($aActionTime);
            $sResultFilename = 'action.'.$sFilename;
            file_put_contents($sResultFilename, array2string($aActionTime));
        }
    }
}
