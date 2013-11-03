<?php

function find_Lest_Unknown_Cell($tmp_array)
{
    $least_unknown_val = '123456789';
    foreach($tmp_array as $tmp_key => $tmp_val)
    {
        if(strlen($tmp_val) > 1 && strlen($tmp_val) < strlen($least_unknown_val))
        {
            $least_unknown_key = $tmp_key;
            $least_unknown_val = $tmp_val;
        }
    }
    $least_unknown_cell['key'] = $least_unknown_key;
    $least_unknown_cell['val'] = $least_unknown_val;
    return $least_unknown_cell;
}

$init_arry=array(
8,1246,24569,2347,12357,1234,13569,4579,1345679,
12459,124,3,6,12578,1248,1589,45789,14579,
1456,7,456,348,9,1348,2,458,13456,
123469,5,2469,2389,2368,7,1689,2489,12469,
12369,12368,269,2389,4,5,7,289,1269,
24679,2468,24679,1,268,2689,5689,3,24569,
23457,234,1,23479,237,2349,359,6,8,
23467,2346,8,5,2367,23469,39,1,2379,
23567,9,2567,2378,123678,12368,4,257,2357
);

var_dump(find_Lest_Unknown_Cell($init_arry));
