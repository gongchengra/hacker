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
$tmp_stack=array();
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
$message_log = '05-sudoku.log';
$message = '';
$found_flag = true;
while(false != $found_flag)
{
    $found_flag = false;
    $tmp_known = 0;
    foreach($tmp_array as $tmp_key => $tmp_val)
    {
        if(1 == strlen($tmp_val))
        {
            $tmp_known++;
        }
        else
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
            foreach ($same_row_array as $same_row_key)
            {
                if(1 == strlen($tmp_array[$same_row_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_row_key]))
                {
                    $tmp_array[$tmp_key] = str_replace($tmp_array[$same_row_key],'',$tmp_array[$tmp_key]);
                    echo "deleted ". $tmp_array["$same_row_key"]. " from ". $tmp_key. " due to value in ". $same_row_key. "\n";
                }
            }
            foreach ($same_column_array as $same_column_key)
            {
                if(1 == strlen($tmp_array[$same_column_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_column_key]))
                {
                    $tmp_array[$tmp_key] = str_replace($tmp_array[$same_column_key],'',$tmp_array[$tmp_key]);
                    echo "deleted ". $tmp_array["$same_column_key"]. " from ". $tmp_key. " due to value in ". $same_column_key. "\n";
                }
            }
            foreach ($same_block_array as $same_block_key)
            {
                if(1 == strlen($tmp_array[$same_block_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_block_key]))
                {
                    $tmp_array[$tmp_key] = str_replace($tmp_array[$same_block_key],'',$tmp_array[$tmp_key]);
                    echo "deleted ". $tmp_array["$same_block_key"]. " from ". $tmp_key. " due to value in ". $same_block_key. "\n";
                }
            }
            if(0 == strlen($tmp_array[$tmp_key]))
            {
                echo "No solution";
                $found_flag = false;
            }
            if(1 == strlen($tmp_array[$tmp_key]))
            {
                $tmp_known++;
                $found_flag = true;
            }
        }
    }
    if($tmp_known == $known_number) $found_flag = false;
    $known_number = $tmp_known;
}

$tmp_stack = array();
array_push($tmp_stack, $tmp_array);
foreach($tmp_array as $tmp_key => $tmp_value)
{
    if(strlen($tmp_value) > 1)
    {
        array_push($tmp_stack, $tmp_key, $tmp_value);
    }
}
$last_unknown_value = array_pop($tmp_stack);
$last_unknown_key = array_pop($tmp_stack);
$force_iterator = str_split($last_unknown_value);
foreach($force_iterator as $force_value)
{
    $tmp_array[$last_unknown_key] = $force_value;
    $found_flag = true;
    while(false != $found_flag)
    {
        $tmp_known = 0;
        foreach($tmp_array as $tmp_key => $tmp_val)
        {
            if(1 == strlen($tmp_val))
            {
                $tmp_known++;
            }
            else
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
                foreach ($same_row_array as $same_row_key)
                {
                    if(1 == strlen($tmp_array[$same_row_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_row_key]))
                    {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_row_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_row_key"]. " from ". $tmp_key. " due to value in ". $same_row_key. "\n";
                    }
                }
                foreach ($same_column_array as $same_column_key)
                {
                    if(1 == strlen($tmp_array[$same_column_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_column_key]))
                    {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_column_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_column_key"]. " from ". $tmp_key. " due to value in ". $same_column_key. "\n";
                    }
                }
                foreach ($same_block_array as $same_block_key)
                {
                    if(1 == strlen($tmp_array[$same_block_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_block_key]))
                    {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_block_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_block_key"]. " from ". $tmp_key. " due to value in ". $same_block_key. "\n";
                    }
                }
                if(0 == strlen($tmp_array[$tmp_key]))
                {
                    echo "No solution";
                    break 2;
                }
                if(1 == strlen($tmp_array[$tmp_key]))
                {
                    $tmp_known++;
                    $found_flag = true;
                }
            }
        }
        if($tmp_known == $known_number) $found_flag = false;
        $known_number = $tmp_known;
    }
    if(81 == $known_number)
    {
        break;
    }
    else
    {
    }

}
$message .=  "Final Result: \n";
foreach($tmp_array as $key => $value)
{
    $message .= $value.' ';
    if(0 == $key%9) $message .= "\n";
}

file_put_contents($message_log, $message);
