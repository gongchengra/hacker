#!/usr/local/bin/php
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
//echo $known_number;
//var_dump($tmp_array);
//if(0)
//{
while($known_number < 81)
{
    $tmp_known = 0;
    foreach($tmp_array as $tmp_key => $tmp_val)
    {
        $row_number = intval( ($tmp_key-1) / 9) + 1;
        $column_number = ($tmp_key-1) % 9 + 1;
        if(49 == $tmp_key)
        {
//            echo $tmp_key. ' '. $row_number. ' '. $column_number."\n";
//            print_r($tmp_val);
        }
        //echo $row_number. " ". $column_number. "\n";
        if(count($tmp_val) > 1)
        {
            //print_r($tmp_val);
            foreach($tmp_val as $val)
            {
                $val_counter = 0;
                for($column_key=1; $column_key<10; $column_key++)
                {
                    $same_row = ($row_number - 1) * 9 + $column_key;
                    if(49 == $tmp_key)
                    {
                    //    echo 'val '. $val. ' '. $same_row. "\n";
                    }
                    if(false !== array_search($val, $tmp_array[$same_row]))
                    {
                        $val_counter++;
                        $remember_row = $same_row;
                    }
                }
                if(1 == $val_counter)
                {
                    $tmp_array[$remember_row] = array($val);
                    echo 'same_row '. $remember_row. ' '. $val. "\n";
                }
                $val_counter = 0;
                for($row_key=0;$row_key<9;$row_key++)
                {
                    $same_column = $row_key*9+$column_number;
                    if(49 == $tmp_key)
                    {
                    //    echo 'val '. $val. ' '. $same_column. "\n";
                    }
                    if(false !== array_search($val, $tmp_array[$same_column]))
                    {
                        $val_counter++;
                        $remember_column = $same_column;
                    }
                }
                if(1 == $val_counter)
                {
                    $tmp_array[$remember_column] = array($val);
                    echo 'same_column '. $remember_column. ' '. $val. "\n";
                }
                $val_counter = 0;
                for($block_key=0;$block_key<9;$block_key++)
                {
                    $same_block = intval(($row_number - 1)/3)*3*9+intval(($tmp_key - 1)%9/3)*3 + 1;
                    $same_block += intval($block_key/3)*9+ $block_key%3;
                    //echo $same_block. "\n";
                    if(49 == $tmp_key && 61 == $val)
                    {
                        echo 'val '. $val. ' '. $same_block. "\n";
                        print_r($tmp_array[$same_block]);
                    }
                    if(false !== array_search($val, $tmp_array[$same_block]))
                    {
                        $val_counter++;
                        $remember_block = $same_block;
                    }
                }
                if(1 == $val_counter)
                {
                    $tmp_array[$remember_block] = array($val);
                    echo 'same_block '. $remember_block. ' '. $val. "\n";
                }
            }
        }
        else
        {
            //echo $tmp_key. ' '. $tmp_val[0]. "\n";
            $tmp_known++;
            for($column_key=1; $column_key<10; $column_key++)
            {
                $same_row = ($row_number - 1) * 9 + $column_key;
                if(count($tmp_array[$same_row]) > 1)
                {
                    $tmp_array[$same_row]=array_diff($tmp_array[$same_row],$tmp_val);
                }
            }
            for($row_key=0;$row_key<9;$row_key++)
            {
                $same_column = $row_key*9+$column_number;
                if(count($tmp_array[$same_column]) > 1)
                {
                    $tmp_array[$same_column]=array_diff($tmp_array[$same_column],$tmp_val);
                }
            }
            for($block_key=0;$block_key<9;$block_key++)
            {
                $same_block = intval(($row_number - 1)/3)*3*9+intval($tmp_key%9/3)*3 + 1;
                $same_block += intval($block_key/3)*9+ $block_key%3;
                //echo $same_block."\t";
                if(count($tmp_array[$same_block]) > 1)
                {
                    $tmp_array[$same_block]=array_diff($tmp_array[$same_block],$tmp_val);
                }
            }
        }
    }
    //if($flag_known < $tmp_known)
    //    $flag_known = $tmp_known;
    //else break;
    $known_number=$tmp_known;
}
//var_dump($tmp_array);
foreach($tmp_array as $key => $value)
{
    echo join('',$value).' ';
    if(0 == $key%9) echo "\n";
}
