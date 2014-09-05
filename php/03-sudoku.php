#!/usr/bin/php
<?php
$init_arry=array(
    0,0,0,0,0,0,0,0,0,
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
easy   
    0,0,0,0,0,0,0,0,0,
    0,2,3,0,0,0,7,8,0,
    1,0,0,4,0,6,0,0,9,
    4,0,0,0,5,0,0,0,1,
    9,0,0,0,0,0,0,0,6,
    0,6,0,0,0,0,0,9,0,
    0,0,5,0,0,0,8,0,0,
    0,0,0,3,0,1,0,0,0,
    0,0,0,0,9,0,0,0,0
answer
5 4 9 7 3 8 1 6 2 
6 2 3 9 1 5 7 8 4 
1 8 7 4 2 6 3 5 9 
4 3 8 6 5 9 2 7 1 
9 5 1 8 7 2 4 3 6 
7 6 2 1 4 3 5 9 8 
3 9 5 2 6 4 8 1 7 
2 7 6 3 8 1 9 4 5 
8 1 4 5 9 7 6 2 3 

hard 
    8,0,0,0,0,0,0,0,0,
    0,0,3,6,0,0,0,0,0,
    0,7,0,0,9,0,2,0,0,
    0,5,0,0,0,7,0,0,0,
    0,0,0,0,4,5,7,0,0,
    0,0,0,1,0,0,0,3,0,
    0,0,1,0,0,0,0,6,8,
    0,0,8,5,0,0,0,1,0,
    0,9,0,0,0,0,4,0,0
 */

$tmp_array=array();
$key = 0;
$known_number = 0;
foreach($init_arry as $number)
{
    $key++;
    if(0 == $number)
    {
        $tmp_array[$key] = "123456789";
    }
    else
    {
        $tmp_array[$key]= "$number";
        $known_number++;
    }
}
//var_dump($tmp_array);
$message_log = '03-sudoku.log';
$message = '';
//while($known_number < 81)
//{
for($i=0;$i<11;$i++)
{
    $tmp_known = 0;
    foreach($tmp_array as $tmp_key => $tmp_val)
    {
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
        if(strlen($tmp_val) > 1)
        {
            if($tmp_key == 2) 
            {
                //$message .= $tmp_val."\n"; 
            }
            $tmp_val_array = str_split($tmp_val);
            foreach($tmp_val_array as $val)
            {
                $row_counter = 0;
                foreach ($same_row_array as $same_row_key)
                {
                    if(false !== strpos($tmp_array[$same_row_key], $val))
                    {
                        $row_counter++;
                        $remember_row = $same_row_key;
                    }
                }
                if(1 == $row_counter && strlen($tmp_array[$remember_row]) > 1)
                {
                    $tmp_array[$remember_row] = "$val";
                    $message .= 'tmp_key '. $tmp_key. ' same_row '. $remember_row. ' '. $val. "\n";
                }
                $column_counter = 0;
                foreach ($same_column_array as $same_column_key)
                {
                    if(false !== strpos($tmp_array[$same_column_key], $val))
                    {
                        $column_counter++;
                        $remember_column = $same_column_key;
                    }
                    if($tmp_key == 2) 
                    {
                       // $message .= ((false == strpos($tmp_array[$same_column_key], $val))?'==':'!=')."\n";
                       // $temp = $tmp_array[$same_column_key];
                       // $message .= $same_column_key. ' '. $temp. ' '. $val. ' '. $column_counter. "\n"; 
                    }
                }
                if(1 == $column_counter && strlen($tmp_array[$remember_column]) > 1)
                {
                    $tmp_array[$remember_column] = "$val";
                    $message .= 'tmp_key '. $tmp_key. ' same_column '. $remember_column. ' '. $val. "\n";
                }
                $block_counter = 0;
                foreach ($same_block_array as $same_block_key)
                {
                    if(false !== strpos($tmp_array[$same_block_key], $val))
                    {
                        $block_counter++;
                        $remember_block = $same_block_key;
                    }
                }
                if(1 == $block_counter && strlen($tmp_array[$remember_block]) > 1)
                {
                    $tmp_array[$remember_block] = "$val";
                    $message .= 'tmp_key '. $tmp_key. ' same_block '. $remember_block. ' '. $val. "\n";
                }
            }
        }
        else
        {
            $tmp_known++;
            foreach ($same_row_array as $same_row_key)
            {
                //$message .= 'same_row_key ' .$same_row_key. ' strlen '. strlen($tmp_array[$same_row_key]). "\n";
                if(strlen($tmp_array[$same_row_key]) > 1 && (false !== strpos($tmp_array[$same_row_key], $tmp_val)))
                {
                    $tmp_array[$same_row_key] = str_replace($tmp_val, '', $tmp_array[$same_row_key]);
                    $message .= 'Row Removed '. $tmp_val. ' from '.$same_row_key."\n";
                }
            }
            foreach ($same_column_array as $same_column_key)
            {
                if(strlen($tmp_array[$same_column_key]) > 1 && (false !== strpos($tmp_array[$same_column_key], $tmp_val)))
                {
                    $tmp_array[$same_column_key] = str_replace($tmp_val, '', $tmp_array[$same_column_key]);
                    $message .= 'column Removed '. $tmp_val. ' from '.$same_column_key."\n";
                }
            }
            foreach ($same_block_array as $same_block_key)
            {
                if(strlen($tmp_array[$same_block_key]) > 1 && (false !== strpos($tmp_array[$same_block_key], $tmp_val)))
                {
                    $tmp_array[$same_block_key] = str_replace($tmp_val, '', $tmp_array[$same_block_key]);
                    $message .= 'block Removed '. $tmp_val. ' from '.$same_block_key."\n";
                }
            }
        }
        $message .= $tmp_key. "\n";
        foreach($tmp_array as $key => $value)
        {
            $message .= $value.' ';
            if(0 == $key%9) $message .= "\n";
        }
    }
    $known_number=$tmp_known;
}
//}
file_put_contents($message_log, $message);
