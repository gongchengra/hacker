#!/usr/bin/php
<?php
/*
 * Problem:
Sorting
Write a PHP script which takes the following array
$data=array(
    array(
        'name'=>'Julie',
        'key'=>'64489c85dc2fe0787b85cd87214b3810'
        'age'=>20
    ),
    array(
        'name'=>'Martin',
        'key'=>'bb07c989b57c25fd7e53395c3e118185',
        'age'=>18
    ),
    array(
        'name'=>'Lucy',
        'key'=>'ab3aec6d954571c7551a186ea1cd98ff',
        'age'=>100
    ),
    array(
        'name'=>'Jessica',
        'age'=>25,
        'key'=>'e1a118c9178aa3538f39a9c8131938ed'
    ),
);

Write function with this signature
    (you can create new functions or use existing php functions)
    function sortData($col, $order)
    {

    }

Which takes 'name', 'age' or 'key' as the $col parameter and 'asc' or 'desc' as the 
    $order parameter and sorts the $data array accordingly

    Answer:

Author: gongcheng_ph@hotmail.com
Version:    v1
Date:       2013-06-09
Desc:       Sort Array according to col and order
 */

$data=array(
    array(
        'name'=>'Julie',
        'key'=>'64489c85dc2fe0787b85cd87214b3810',
        'age'=>20
    ),
    array(
        'name'=>'Martin',
        'key'=>'bb07c989b57c25fd7e53395c3e118185',
        'age'=>18
    ),
    array(
        'name'=>'Lucy',
        'key'=>'ab3aec6d954571c7551a186ea1cd98ff',
        'age'=>100
    ),
    array(
        'name'=>'Jessica',
        'age'=>25,
        'key'=>'e1a118c9178aa3538f39a9c8131938ed'
    )
);

function sortData($multi_array,$col,$order)
{
    $sort_order = ($order == 'asc')?SORT_ASC:SORT_DESC;
    if(is_array($multi_array))
    {
        foreach ($multi_array as $row_array){
            if(is_array($row_array)){
                $key_array[] = $row_array[$col];
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
    array_multisort($key_array,$sort_order,$multi_array);
    return $multi_array;
}

echo "Test sort by name asc order: ".PHP_EOL;
print_r(sortData($data,'name','asc'));
echo "Test sort by name desc order: ".PHP_EOL;
print_r(sortData($data,'name','desc'));

echo "Test sort by age asc order: ".PHP_EOL;
print_r(sortData($data,'age','asc'));
echo "Test sort by age desc order: ".PHP_EOL;
print_r(sortData($data,'age','desc'));

echo "Test sort by key asc order: ".PHP_EOL;
print_r(sortData($data,'key','asc'));
echo "Test sort by key desc order: ".PHP_EOL;
print_r(sortData($data,'key','desc'));
exit;
?>

