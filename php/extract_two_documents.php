#!/usr/bin/php
<?php
if ($argc != 5 || in_array($argv[1], array('--help', '-help', '-h', '-?'))) {
    echo "Useage: Input 4 parameters: \n";
    echo "The first one is where you want to search the data.(The data contains all entites in our case, one per line.) \n";
    echo "The second one is the data you want to search. (The new entities in our case, one per line.)\n";
    echo "The third one is the data mapping to the first one. (The entity id corresponding to the dorp id.)\n";
    echo "The last one is where do you want to put the matching result.\n";
    echo "For example, ".$argv[0]." data1 data2 data3 founded will fetch a line of data from data2 and search whether the line \n";
    echo "is contained in data1, if a matching data is found, it will write the corresponing value in data3 to the file founded. \n";
    echo "Otherwise, it will print one screen it is not found in data1.";
} else {
    $data1    =    file($argv[1]);
    $data2    =    file($argv[2]);
    $data3    =    file($argv[3]);
    $found    =    $argv[4];
    $size1    =    sizeof($data1);
    $size2    =    sizeof($data2);
    $founded  =    0;
    $match    =    '';
    foreach ($data2 as $val2) {
        $flag   =   0;
        $key    =   0;
        foreach ($data1 as $val1) {
            if ($val1 == $val2) {
                $founded++;
                $match .= $data3[$key];
            } else {
                $flag++;
            }
            $key++;
        }
        if ($flag == $size1) {
            echo $val2."is not in ".$argv[1]."\n";
        }
    }
    echo 'the size of '.$argv[1].' is '.$size1."\n";
    echo 'the size of '.$argv[2].' is '.$size2."\n";
    echo 'the number of entities in'.$argv[2].' found in '.$argv[1].' is '.$founded."\n";
    echo 'the matching entityid for entities in '.$argv[2].' found in '.$argv[1].' are in '.$found."\n";
    file_put_contents($found, $match);
}
