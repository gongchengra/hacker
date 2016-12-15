<?PHP

$array = array(
    1 => 'a',
    '1' => 'b',
    1.5 => 'c',
    true => 'd',
);
var_dump($array);
$array = array(
    'foo' => 'bar',
    'bar' => 'foo',
    100 => -100,
    -100 => 100,
);
var_dump($array);
$array = array(
    'a',
    'b',
    6 => 'c',
    'd',
);
var_dump($array);
$array = array(
    "foo" => "bar",
    42    => 24,
    "multi" => array(
        "dimensional" => array(
            "array" => "foo"
        )
    )
);

var_dump($array["foo"]);
var_dump($array[42]);
var_dump($array["multi"]["dimensional"]["array"]);

function getArray() {
    return array(1, 2, 3);
}

// on PHP 5.4
$secondElement = getArray()[1];

// previously
$tmp = getArray();
$secondElement = $tmp[1];

// or
list(, $secondElement) = getArray();

$arr = array(5 => 1, 12 => 2);

$arr[] = 56;    // This is the same as $arr[13] = 56;
// at this point of the script

$arr["x"] = 42; // This adds a new element to
// the array with key "x"

unset($arr[5]); // This removes the element from the array

unset($arr);    // This deletes the whole array
