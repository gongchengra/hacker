#!/usr/bin/php
<?php
$init_arry=array(
    0,0,0,0,0,0,0,0,0,/*数独初始化，其中0表示数字未给出*/
    0,2,3,0,0,0,7,8,0,
    1,0,0,4,0,6,0,0,9,
    4,0,0,0,5,0,0,0,1,
    9,0,0,0,0,0,0,0,6,
    0,6,0,0,0,0,0,9,0,
    0,0,5,0,0,0,8,0,0,
    0,0,0,3,0,1,0,0,0,
    0,0,0,0,9,0,0,0,0
);
/*
0,0,0,0,0,0,0,0,0,
6,2,3,0,0,0,7,8,0,
1,0,0,4,0,6,0,0,9,
4,0,0,6,5,9,0,0,1,
9,0,0,0,0,0,0,0,6,
0,6,0,0,0,0,0,9,8,
0,9,5,0,0,0,8,0,0,
0,0,0,3,0,1,9,0,0,
0,0,0,0,9,0,0,0,0

5 4 9 7 3 8 1 6 2 
6 2 3 9 1 5 7 8 4 
1 8 7 4 2 6 3 5 9 
4 3 8 6 5 9 2 7 1 
9 5 1 8 7 2 4 3 6 
7 6 2 1 4 3 5 9 8 
3 9 5 2 6 4 8 1 7 
2 7 6 3 8 1 9 4 5 
8 1 4 5 9 7 6 2 3 
 */

$tmp_array=array();
$key = 0;
$known_number = 0;
foreach($init_arry as $number)
{
    $key++;
    if(0 == $number)
    {
        $tmp_array[$key] = array(1,2,3,4,5,6,7,8,9);
    }
    else
    {
        $tmp_array[$key]= array($number);
        $known_number++;
    }
}
$message_log = 'sudoku.log';
$message = '';
while($known_number < 81)
{
    $tmp_known = 0;
    foreach($tmp_array as $tmp_key => $tmp_val)
    {
        if(2 == $tmp_key)
        {
            $message .= join('',$tmp_val). "\n";
        }
        $row_number = intval( ($tmp_key-1) / 9) + 1;
        $column_number = ($tmp_key-1) % 9 + 1;
        $same_row_array = array();
        $same_column_array = array();
        $same_block_array = array();
        for($counter=0; $counter < 9; $counter++)
        {
            $same_row = ($row_number - 1) * 9 + $counter + 1;
            $same_row_array[$counter] = $same_row;
            $same_column = $counter * 9 + $column_number;
            $same_column_array[$counter] = $same_column;
            $same_block = intval(($row_number - 1) / 3 ) * 3 * 9 + intval(($tmp_key - 1) % 9 / 3) * 3 + 1;
            $same_block += intval($counter / 3) * 9 + $counter % 3;
            $same_block_array[$counter] = $same_block;
        }
        if(count($tmp_val) > 1)
        {
            foreach($tmp_val as $val)
            {
                $val_counter = 0;
                foreach ($same_row_array as $same_row_key)
                {
                    if(false !== array_search($val, $tmp_array[$same_row_key]))
                    {
                        $val_counter++;
                        $remember_row = $same_row_key;
                    }
                }
                if(1 == $val_counter)
                {
                    //unset($tmp_array[$remember_row]);
                    $tmp_array[$remember_row] = array($val);
                    $message .= 'tmp_key '. $tmp_key. ' same_row '. $remember_row. ' '. $val. "\n";
                    $message .= join('',$tmp_array[$remember_row]).' '."\n";
                }
                $val_counter = 0;
                foreach ($same_column_array as $same_column_key)
                {
                    if(false !== array_search($val, $tmp_array[$same_column_key]))
                    {
                        $val_counter++;
                        $remember_column = $same_column_key;
                    }
                }
                if(1 == $val_counter)
                {
                    //unset($tmp_array[$remember_column]);
                    $tmp_array[$remember_column] = array($val);
                    $message .= 'tmp_key '. $tmp_key. ' same_column '. $remember_column. ' '. $val. "\n";
                    $message .= join('',$tmp_array[$remember_column]).' '."\n";
                }
                $val_counter = 0;
                foreach ($same_block_array as $same_block_key)
                {
                    if(false !== array_search($val, $tmp_array[$same_block_key]))
                    {
                        $val_counter++;
                        $remember_block = $same_block_key;
                    }
                }
                if(1 == $val_counter)
                {
                    //unset($tmp_array[$remember_block]);
                    $tmp_array[$remember_block] = array($val);
                    $message .= 'tmp_key '. $tmp_key. ' same_block '. $remember_block. ' '. $val. "\n";
                    $message .= join('',$tmp_array[$remember_block]).' '."\n";
                }
            }
        }
        else
        {
            $tmp_known++;
            foreach ($same_row_array as $same_row_key)
            {
                if(count($tmp_array[$same_row_key]) > 1)
                {
                    $tmp_array[$same_row_key]=array_diff($tmp_array[$same_row_key],$tmp_val);
                    $message .= 'Row Removed '.join('',$tmp_val).' from '.$same_row_key."\n";
                }
            }
            foreach ($same_column_array as $same_column_key)
            {
                if(count($tmp_array[$same_column_key]) > 1)
                {
                    $tmp_array[$same_column_key]=array_diff($tmp_array[$same_column_key],$tmp_val);
                    $message .= 'Column Removed '.join('',$tmp_val).' from '.$same_column_key."\n";
                }
            }
            foreach ($same_block_array as $same_block_key)
            {
                if(count($tmp_array[$same_block_key]) > 1)
                {
                    $tmp_array[$same_block_key]=array_diff($tmp_array[$same_block_key],$tmp_val);
                    $message .= 'Block Removed '.join('',$tmp_val).' from '.$same_block_key."\n";
                }
            }
        }
    }
    $known_number=$tmp_known;
}
//var_dump($tmp_array);
foreach($tmp_array as $key => $value)
{
    $message .= join('',$value).' ';
    if(0 == $key%9) $message .= "\n";
}
file_put_contents($message_log, $message);
