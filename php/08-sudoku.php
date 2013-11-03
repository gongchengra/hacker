#!/usr/local/bin/php
<?php
$init_arry=array(
    8,0,0,0,0,0,0,0,0,
    0,0,3,6,0,0,0,0,0,
    0,7,0,0,9,0,2,0,0,
    0,5,0,0,0,7,0,0,0,
    0,0,0,0,4,5,7,0,0,
    0,0,0,1,0,0,0,3,0,
    0,0,1,0,0,0,0,6,8,
    0,0,8,5,0,0,0,1,0,
    0,9,0,0,0,0,4,0,0
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

function calculate_same_rcb($tmp_key)
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
    $row_column_block['row'] = $same_row_array;
    $row_column_block['column'] = $same_column_array;
    $row_column_block['block'] = $same_block_array;
    return $row_column_block;
}

function delete_duplicate_value($tmp_array)
{
    do{
        $delete_flag = false;
        foreach($tmp_array as $tmp_key => $tmp_val) {
            if(strlen($tmp_val) == 1) {
                $row_column_block = calculate_same_rcb($tmp_key);
                $same_row_array = $row_column_block['row'];
                $same_column_array = $row_column_block['column'];
                $same_block_array = $row_column_block['block'];
                foreach ($same_row_array as $same_row_key) {
                    if($same_row_key != $tmp_key && strlen($tmp_array[$same_row_key]) > 1 && false !== strpos($tmp_array[$same_row_key], $tmp_array[$tmp_key]))
                    {
                        $tmp_array[$same_row_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_row_key]);
                        $delete_flag = true;
                    }
                }
                foreach ($same_column_array as $same_column_key) {
                    if($same_column_key != $tmp_key && strlen($tmp_array[$same_column_key]) > 1 && false !== strpos($tmp_array[$same_column_key], $tmp_array[$tmp_key]))
                    {
                        $tmp_array[$same_column_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_column_key]);
                        $delete_flag = true;
                    }
                }
                foreach ($same_block_array as $same_block_key) {
                    if($same_block_key != $tmp_key && strlen($tmp_array[$same_block_key]) > 1 && false !== strpos($tmp_array[$same_block_key], $tmp_array[$tmp_key]))
                    {
                        $tmp_array[$same_block_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_block_key]);
                        $delete_flag = true;
                    }
                }
            }
        }
    }while(false != $delete_flag);
    return $tmp_array;
}

function fill_Cells_With_One_Possibility($tmp_array)
{
    do{
       $found_flag = false;
        foreach($tmp_array as $tmp_key => $tmp_val) {
            $tmp_val_array = str_split($tmp_val);
            foreach($tmp_val_array as $val)
            {
                $row_column_block = calculate_same_rcb($tmp_key);
                $same_row_array = $row_column_block['row'];
                $same_column_array = $row_column_block['column'];
                $same_block_array = $row_column_block['block'];
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
                    $found_flag = true;
                }
                $column_counter = 0;
                foreach ($same_column_array as $same_column_key)
                {
                    if(false !== strpos($tmp_array[$same_column_key], $val))
                    {
                        $column_counter++;
                        $remember_column = $same_column_key;
                    }
                }
                if(1 == $column_counter && strlen($tmp_array[$remember_column]) > 1)
                {
                    $tmp_array[$remember_column] = "$val";
                    $found_flag = true;
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
                    $found_flag = true;
                }
            }
        }
    } while(false != $found_flag);
    return $tmp_array;
}

function simplify_Matrix($tmp_array)
{
    do{
        $before_simplify = $tmp_array;
        $tmp_array = delete_duplicate_value($tmp_array);
        $tmp_array = fill_Cells_With_One_Possibility($tmp_array);
        $after_simplify = $tmp_array;
    } while($before_simplify != $after_simplify);
    return $tmp_array;
}

function check_Matrix($matrix)
{
    foreach($matrix as $tmp_key => $tmp_val)
    {
        $row_column_block = calculate_same_rcb($tmp_key);
        $same_row_array = $row_column_block['row'];
        $same_column_array = $row_column_block['column'];
        $same_block_array = $row_column_block['block'];
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

$tmp_array = simplify_Matrix($tmp_array);
$tmp_array_numbers = array();
foreach ($tmp_array as $key => $value)
{
    //        echo $value. ' ';
    //        if(0 == ($key+1)%9) echo "\n";
    $tmp_array_numbers[$key] = str_split($value);
    $walk[$key] = 0;
    $count_ball[$key] = strlen($value);
}
//if(0)
//{
    do{
        $copy_tmp_array_numbers = $tmp_array_numbers;
        $tmp_matrix = array();
        foreach($walk as $k => $v)
        {
            if(0 == $copy_tmp_array_numbers[$k][$v])
            {
                continue 2;
            }
            $tmp_matrix[$k] = $copy_tmp_array_numbers[$k][$v];
            $row_column_block = calculate_same_rcb($k);
            $same_row_array = $row_column_block['row'];
            $same_column_array = $row_column_block['column'];
            $same_block_array = $row_column_block['block'];
            foreach ($same_row_array as $same_row_key) {
                if($k != $same_row_key && count($copy_tmp_array_numbers[$same_row_key]) > 1 
                    && false != array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key]))
                {
                    $copy_tmp_array_numbers[array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key])] = 0;
                }
            }
            foreach ($same_column_array as $same_column_key) {
                if($k != $same_column_key && count($copy_tmp_array_numbers[$same_column_key]) > 1 
                    && false != array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key]))
                {
                    $copy_tmp_array_numbers[array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key])] = 0;
                }
            }
            foreach ($same_block_array as $same_block_key) {
                if($k != $same_block_key && count($copy_tmp_array_numbers[$same_block_key]) > 1 
                    && false != array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key]))
                {
                    $copy_tmp_array_numbers[array_search($tmp_matrix[$k],$copy_tmp_array_numbers[$same_row_key])] = 0;
                }
            }
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
//}
