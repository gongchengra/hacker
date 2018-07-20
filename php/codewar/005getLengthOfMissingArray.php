<?php
/*
You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
	But one array is missing!


	You have to write a method, that return the length of the missing array.

	Example:
[[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]] --> 3


	If the array of arrays is null/nil or empty, the method should return 0.

		When an array in the array is null or empty, the method should return 0 too!
		There will always be a missing element and its length will be always between the given arrays. 
 */
//my
function getLengthOfMissingArray($arrayOfArrays) {
	if(empty($arrayOfArrays)) {
		return 0;
	}
	$lengthArray = [];
	foreach($arrayOfArrays as $k => $v){
		if(empty($v)){return 0;}
		$lengthArray[$k] = count($v);
	}
	sort($lengthArray);
	$low = $lengthArray[0];
	foreach($lengthArray as $k => $v) {
		if($v > $low + $k){
			return $v-1;
		}
	}
}
echo getLengthOfMissingArray([ [ 1, 2 ], [ 4, 5, 1, 1 ], [ 1 ], [ 5, 6, 7, 8, 9 ]]);

//best
function getLengthOfMissingArray($arrayOfArrays) {
	if(!$arrayOfArrays || in_array(0, $length_array = array_map('count', $arrayOfArrays))) return 0;
	$compare_array = range(min($length_array),max($length_array));
	return array_values(array_diff($compare_array, $length_array))[0];
}
