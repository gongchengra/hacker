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
    /*
    0,0,0,9,0,0,8,0,0,
    4,3,0,0,0,8,0,9,6,
    0,0,9,0,0,6,5,7,3,
    1,4,8,0,0,0,0,0,0,
    0,0,7,2,0,5,1,0,0,
    0,0,0,0,0,0,7,3,9,
    2,1,4,6,0,0,3,0,0,
    6,7,0,1,0,0,0,8,2,
    0,0,5,0,0,7,0,0,0
     */
);
$message_log = 'sudoku.log';
$message = '';
$tmp_array=array();
$known_number = 0;

foreach($init_arry as $key => $number)
{
    if(0 == $number) {
        $tmp_array[$key] = "123456789";
    }
    else {
        $tmp_array[$key]= "$number";
        $known_number++;
    }
}

if($known_number < 17) {
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
    do {
        $delete_flag = false;
        foreach($tmp_array as $tmp_key => $tmp_val) {
            if(strlen($tmp_val) == 1) {
                $row_column_block = calculate_same_rcb($tmp_key);
                $same_row_array = $row_column_block['row'];
                $same_column_array = $row_column_block['column'];
                $same_block_array = $row_column_block['block'];
                foreach ($same_row_array as $same_row_key) {
                    if($same_row_key != $tmp_key && strlen($tmp_array[$same_row_key]) > 1
                        && false !== strpos($tmp_array[$same_row_key], $tmp_array[$tmp_key])) {
                        $tmp_array[$same_row_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_row_key]);
//                        echo "deleted ". $tmp_array["$tmp_key"]. " from ". $same_row_key. " due to value in ". $tmp_key. "\n";
                        $delete_flag = true;
                    }
                }
                foreach ($same_column_array as $same_column_key) {
                    if($same_column_key != $tmp_key && strlen($tmp_array[$same_column_key]) > 1
                        && false !== strpos($tmp_array[$same_column_key], $tmp_array[$tmp_key])) {
                        $tmp_array[$same_column_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_column_key]);
//                        echo "deleted ". $tmp_array["$tmp_key"]. " from ". $same_column_key. " due to value in ". $tmp_key. "\n";
                        $delete_flag = true;
                    }
                }
                foreach ($same_block_array as $same_block_key) {
                    if($same_block_key != $tmp_key && strlen($tmp_array[$same_block_key]) > 1
                        && false !== strpos($tmp_array[$same_block_key], $tmp_array[$tmp_key])) {
                        $tmp_array[$same_block_key] = str_replace($tmp_array[$tmp_key],'',$tmp_array[$same_block_key]);
//                        echo "deleted ". $tmp_array["$tmp_key"]. " from ". $same_block_key. " due to value in ". $tmp_key. "\n";
                        $delete_flag = true;
                    }
                }
            }
        }
    } while(false != $delete_flag);
    return $tmp_array;
}

function fill_Cells_With_One_Possibility($tmp_array)
{
    do {
       $found_flag = false;
        foreach($tmp_array as $tmp_key => $tmp_val) {
            $tmp_val_array = str_split($tmp_val);
            foreach($tmp_val_array as $val) {
                $row_column_block = calculate_same_rcb($tmp_key);
                $same_row_array = $row_column_block['row'];
                $same_column_array = $row_column_block['column'];
                $same_block_array = $row_column_block['block'];
                $row_counter = 0;
                foreach ($same_row_array as $same_row_key) {
                    if(false !== strpos($tmp_array[$same_row_key], $val)) {
                        $row_counter++;
                        $remember_row = $same_row_key;
                    }
                }
                if(1 == $row_counter && strlen($tmp_array[$remember_row]) > 1) {
                    $tmp_array[$remember_row] = "$val";
//                    echo 'tmp_key '. $tmp_key. ' same_row '. $remember_row. ' '. $val. "\n";
                    $found_flag = true;
                }
                $column_counter = 0;
                foreach ($same_column_array as $same_column_key) {
                    if(false !== strpos($tmp_array[$same_column_key], $val)) {
                        $column_counter++;
                        $remember_column = $same_column_key;
                    }
                }
                if(1 == $column_counter && strlen($tmp_array[$remember_column]) > 1) {
                    $tmp_array[$remember_column] = "$val";
//                    echo 'tmp_key '. $tmp_key. ' same_column '. $remember_column. ' '. $val. "\n";
                    $found_flag = true;
                }
                $block_counter = 0;
                foreach ($same_block_array as $same_block_key) {
                    if(false !== strpos($tmp_array[$same_block_key], $val)) {
                        $block_counter++;
                        $remember_block = $same_block_key;
                    }
                }
                if(1 == $block_counter && strlen($tmp_array[$remember_block]) > 1) {
                    $tmp_array[$remember_block] = "$val";
//                    echo 'tmp_key '. $tmp_key. ' same_block '. $remember_block. ' '. $val. "\n";
                    $found_flag = true;
                }
            }
        }
    } while(false != $found_flag);
    return $tmp_array;
}

function simplify_Matrix($tmp_array)
{
    do {
        $before_simplify = $tmp_array;
        $tmp_array = delete_duplicate_value($tmp_array);
        $tmp_array = fill_Cells_With_One_Possibility($tmp_array);
        $after_simplify = $tmp_array;
    } while($before_simplify != $after_simplify);
    return $tmp_array;
}

function check_Matrix($matrix)
{
    foreach($matrix as $tmp_key => $tmp_val) {
        $row_column_block = calculate_same_rcb($tmp_key);
        $same_row_array = $row_column_block['row'];
        $same_column_array = $row_column_block['column'];
        $same_block_array = $row_column_block['block'];
        if(strlen($tmp_val) == 1)
        {
            foreach ($same_row_array as $same_row_key) {
                if($tmp_key != $same_row_key && 1 == strlen($matrix[$same_row_key]) && $tmp_val == $matrix[$same_row_key]) {
                    return false;
                }
            }
            foreach ($same_column_array as $same_column_key) {
                if($tmp_key != $same_column_key && 1 == strlen($matrix[$same_column_key]) && $tmp_val == $matrix[$same_column_key]) {
                    return false;
                }
            }
            foreach ($same_block_array as $same_block_key) {
                if($tmp_key != $same_block_key && 1 == strlen($matrix[$same_block_key]) && $tmp_val == $matrix[$same_block_key]) {
                    return false;
                }
            }
        }
    }
    return true;
}

function get_Matrix_Status($tmp_array)
{
    $known_number = 0;
    foreach($tmp_array as $tmp_key => $tmp_val) {
        if(0 == strlen($tmp_val)) {
            return 'error';
        }
        if(1 == strlen($tmp_val)) {
            $known_number++;
        }
    }
    if(81 == $known_number) {
        return 'solved';
    }
    else {
        return 'unsolved';
    }
}

function find_Lest_Unknown_Cell($tmp_array)
{
    $least_unknown_val = '123456789';
    foreach($tmp_array as $tmp_key => $tmp_val) {
        if(strlen($tmp_val) > 1 && strlen($tmp_val) < strlen($least_unknown_val)) {
            $least_unknown_key = $tmp_key;
            $least_unknown_val = $tmp_val;
        }
    }
    $least_unknown_cell['key'] = $least_unknown_key;
    $least_unknown_cell['val'] = $least_unknown_val;
    return $least_unknown_cell;
}

$tmp_array = simplify_Matrix($tmp_array);
if(false == check_Matrix($tmp_array))
{
    echo "No solution";
    $message .= "No solution";
    file_put_contents($message_log, $message);
    exit;
}
else
{
    $tmp_stack = array();
    do {
        $matrix_status = get_Matrix_Status($tmp_array);
        if('solved' == $matrix_status) {
            if(true == check_Matrix($tmp_array))
            {
                foreach($tmp_array as $key => $value) {
                    $message .= $value.' ';
                    if(0 == ($key+1)%9) $message .= "\n";
                }
                foreach($tmp_array as $key => $value) {
                    echo $value.' ';
                    if(0 == ($key+1)%9) echo "\n";
                }
                echo "\n";
            }
            if(0 == count($tmp_stack)) {
                break;
            }
            else {
                $top_of_stack = array_pop($tmp_stack);
                $tmp_array = array_pop($tmp_stack);
                $top_of_stack_array = str_split($top_of_stack['val']);
                $first_number_on_top_stack = array_shift($top_of_stack_array);
                $tmp_array[$top_of_stack['key']] = $first_number_on_top_stack;
                //echo 'assume '. $least_unknown_cell['key']. ' is '. $first_number_on_top_stack. "\n";
                $tmp_array = simplify_Matrix($tmp_array);
                if(count($top_of_stack_array) > 0)
                {
                    $top_of_stack['val'] = join('',$top_of_stack_array);
                    array_push($tmp_stack, $tmp_array);
                    array_push($tmp_stack, $top_of_stack);
                }
                //                $tmp_array = array_shift($tmp_stack);
                //                $head_of_stack = array_shift($tmp_stack);
                //                $tmp_array[$head_of_stack['key']] = $head_of_stack['val'];
            }
        }
        if('unsolved' == $matrix_status) {
//            foreach($tmp_array as $key => $value) {
//                echo $value.' ';
//                if(0 == ($key+1)%9) echo "\n";
//            }
            array_push($tmp_stack, $tmp_array);
            $least_unknown_cell = find_Lest_Unknown_Cell($tmp_array);
            //echo 'least_unknow_cell is '. $least_unknown_cell['key']. ' with value of '. $least_unknown_cell['val']. "\n";
            $unknown_cell_array = str_split($least_unknown_cell['val']);
            $first_number_in_unknown_cell = array_shift($unknown_cell_array);
            $least_unknown_cell['val'] = join('',$unknown_cell_array);
            array_push($tmp_stack,$least_unknown_cell);
            $tmp_array[$least_unknown_cell['key']] = $first_number_in_unknown_cell;
            //echo 'assume '. $least_unknown_cell['key']. ' is '. $first_number_in_unknown_cell. "\n";
            $tmp_array = simplify_Matrix($tmp_array);
        }
        if('error' == $matrix_status) {
            if(0 == count($tmp_stack)) {
                $message .= "No solution";
                break;
            }
            else {
                $top_of_stack = array_pop($tmp_stack);
                array_pop($tmp_stack);
                $top_of_stack_array = str_split($top_of_stack['val']);
                $first_number_on_top_stack = array_shift($top_of_stack_array);
                $tmp_array[$top_of_stack['key']] = $first_number_on_top_stack;
                $tmp_array = simplify_Matrix($tmp_array);
                if(count($top_of_stack_array) > 0)
                {
                    $top_of_stack['val'] = join('',$top_of_stack_array);
                    array_push($tmp_stack, $top_of_stack);
                }
            }
        }
    } while(1);
}
file_put_contents($message_log, $message);
