#!/usr/bin/php
<?php
function printhelp($argv)
{
    echo "Useage: Count action and time of a given year.\n";
    echo 'For example, '.$argv[0]." -year 2016 will count the actions in 2016\n";
    echo "The result will be given in two files 2016-ksort.txt and 2016-asort.txt\n";
    echo 'For example, '.$argv[0]." -action hft will count the time of action hft in 2016\n";
}

function file2array($year)
{
    $aActionTime = [];
    for ($i = 1; $i <= 12; ++$i) {
        $filename = $year.str_pad($i, 2, '0', STR_PAD_LEFT).'.txt';
        if (file_exists($filename)) {
            $aFile = file($filename);
            foreach ($aFile as $sLine) {
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
        }
    }

    return $aActionTime;
}

function array2string($aActionTime)
{
    $sActionTime = '';
    foreach ($aActionTime as $sAction => $iTime) {
        $sActionTime .= trim($sAction).' '.$iTime."\n";
    }

    return $sActionTime;
}

if ($argc < 2 || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    printhelp($argv);
} else {
    if ($argv[1] == '-year') {
        $year = $argv[2];
        $aActionTime = file2array($year);
        if ($argc > 3 && $argv[3] == '-action') {
            $sSearchAction = $argv[4];
            $iSumTime = 0;
            foreach ($aActionTime as $sAction => $iTime) {
                if (strpos($sAction, $sSearchAction) !== false) {
                    echo $sAction.' '.$iTime."\n";
                    $iSumTime += $iTime;
                }
            }
            echo $sSearchAction.' '.$iSumTime."\n";
        } else {
            arsort($aActionTime);
            file_put_contents($year.'-asort.txt', array2string($aActionTime));
            ksort($aActionTime);
            file_put_contents($year.'-ksort.txt', array2string($aActionTime));
        }
    }
}
