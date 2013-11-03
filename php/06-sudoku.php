#!/usr/local/bin/php
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
$message_log = '06-sudoku.log';
$message = '';
$tmp_array=array();
$known_number = 0;

foreach($init_arry as $key => $number)
{
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

if($known_number<17)
{
    $message .=  "No Result: \n";
    file_put_contents($message_log, $message);
    exit;
}

function find_Cells_With_One_Possibility($tmp_array)
{
    do{
        $found_flag = false;
        foreach($tmp_array as $tmp_key => $tmp_val) {
            if(strlen($tmp_val) > 1) {
                $row_number = intval($tmp_key / 9);
                $column_number = $tmp_key % 9;
                $same_row_array = array();
                $same_column_array = array();
                $same_block_array = array();
                for($counter=0; $counter < 9; $counter++) {
                    $same_row = $row_number * 9 + $counter;
                    $same_row_array[$counter] = $same_row;
                    $same_column = $counter * 9 + $column_number;
                    $same_column_array[$counter] = $same_column;
                    $same_block = intval($row_number / 3 ) * 3 * 9 + intval($tmp_key % 9 / 3) * 3;
                    $same_block += intval($counter / 3) * 9 + $counter % 3;
                    $same_block_array[$counter] = $same_block;
                }
                foreach ($same_row_array as $same_row_key) {
                    if(1 == strlen($tmp_array[$same_row_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_row_key]))
                    {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_row_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_row_key"]. " from ". $tmp_key. " due to value in ". $same_row_key. "\n";
                    }
                }
                foreach ($same_column_array as $same_column_key) {
                    if(1 == strlen($tmp_array[$same_column_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_column_key])) {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_column_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_column_key"]. " from ". $tmp_key. " due to value in ". $same_column_key. "\n";
                    }
                }
                foreach ($same_block_array as $same_block_key) {
                    if(1 == strlen($tmp_array[$same_block_key]) && false !== strpos($tmp_array[$tmp_key], $tmp_array[$same_block_key])) {
                        $tmp_array[$tmp_key] = str_replace($tmp_array[$same_block_key],'',$tmp_array[$tmp_key]);
                        echo "deleted ". $tmp_array["$same_block_key"]. " from ". $tmp_key. " due to value in ". $same_block_key. "\n";
                    }
                }
                if(0 == strlen($tmp_array[$tmp_key])) {
                    echo "No solution";
                    $found_flag = 'error';
                    break 2;
                }
                if(1 == strlen($tmp_array[$tmp_key])) {
                    $found_flag = true;
                }
            }
        }
    } while(false != $found_flag);
    return $tmp_array;
}

function check_Matrix($matrix)
{
    foreach($matrix as $tmp_key => $tmp_val)
    {
        $row_number = intval($tmp_key / 9);
        $column_number = $tmp_key % 9;
        $same_row_array = array();
        $same_column_array = array();
        $same_block_array = array();
        for($counter=0; $counter < 9; $counter++) {
            $same_row = $row_number * 9 + $counter;
            $same_row_array[$counter] = $same_row;
            $same_column = $counter * 9 + $column_number;
            $same_column_array[$counter] = $same_column;
            $same_block = intval($row_number / 3 ) * 3 * 9 + intval($tmp_key % 9 / 3) * 3;
            $same_block += intval($counter / 3) * 9 + $counter % 3;
            $same_block_array[$counter] = $same_block;
        }
        foreach ($same_row_array as $same_row_key) {
            if($tmp_key != $same_row_key && $tmp_val == $matrix[$same_row_key])
            {
                return false;
            }
        }
        foreach ($same_column_array as $same_column_key) {
            if($tmp_key != $same_column_key && $tmp_val == $matrix[$same_column_key])
            {
                return false;
            }
        }
        foreach ($same_block_array as $same_block_key) {
            if($tmp_key != $same_block_key && $tmp_val == $matrix[$same_block_key])
            {
                return false;
            }
        }
    }
    return true;
}

$tmp_array = find_Cells_With_One_Possibility($tmp_array);
$tmp_array_numbers = array();
foreach ($tmp_array as $key => $value)
{
//    echo $value. ' ';
//    if(0 == ($key+1)%9) echo "\n";
    $tmp_array_numbers[$key] = str_split($value);
    $walk[$key] = 0;
    $count_ball[$key] = strlen($value);
}

do{
    $tmp_matrix = array();
    foreach($walk as $k => $v)
    {
        $tmp_matrix[$k] = $tmp_array_numbers[$k][$v];
    }
    echo join('',$walk)."\n";
//    foreach($tmp_matrix as $key => $value)
//    {
//        echo $value.' ';
//        if(0 == ($key+1)%9) echo "\n";
//    }
    if(true == check_Matrix($tmp_matrix))
    {
        foreach($tmp_matrix as $key => $value)
        {
            $message .= $value.' ';
            if(0 == ($key+1)%9) $message .= "\n";
        }
        file_put_contents($message_log, $message);
        exit;
    }
    $walk[0]++;
    foreach($walk as $kk => $vv) {
        if($walk[$kk] == $count_ball[$kk]) {
                $walk[$kk] = 0;
                $walk[$kk+1] ++;
        }
    }
//}while($walk[0] < 4);
}while($walk[80] < $count_ball[80]);

$message .=  "Final Result: \n";
foreach($tmp_array as $key => $value)
{
    $message .= $value.' ';
    if(0 == $key%9) $message .= "\n";
}
file_put_contents($message_log, $message);

