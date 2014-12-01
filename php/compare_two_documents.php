#!/usr/bin/php
<?php
if ($argc != 3 || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    echo "Useage: Input 2 parameters: \n";
    echo "The first one is where you want to search the data.(The data contains all entites in our case, one per line.) \n";
    echo "The second one is the data you want to search. (The new entities in our case, one per line.)\n";
    echo "For example, ".$argv[0]." data1 data2 will fetch a line of data from data2 and search whether the line \n";
    echo "is contained in data1, if a matching data is found, the number increase.\n";
    echo "Otherwise, it will print one screen it is not found in data1.";
} else {
    $data1      =   file($argv[1]);
    $data2      =   file($argv[2]);
    $size1      =   sizeof($data1);
    $size2      =   sizeof($data2);
    $founded    =   0;
    foreach ($data2 as $val2) {
        $flag = 0;
        foreach ($data1 as $val1) {
            if ($val1 == $val2) {
                $founded++;
                echo $val1;
            } else {
                $flag++;
            }
        }
        if ($flag == $size1) {
            //            echo $val2 . ' is not in '. $argv[2]. "\n";
        }
    }
    echo 'the size of '.$argv[1].' is '.$size1."\n";
    echo 'the size of '.$argv[2].' is '.$size2."\n";
    echo 'the number of entities in '.$argv[2].' found in '.$argv[1].' is '.$founded."\n";
}
