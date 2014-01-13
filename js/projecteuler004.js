//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=4
var isPalindromeNumber = function isPalindromeNumber(N) {
    return (N).toString() === (N).toString().split("").reverse().join("");
}

var getProductArray = function getProductArray(Max, Min) {
    var productArray = [];
    var i;
    for (i = Max; i >= Min; i--) {
        for (j = i; j >= Min; j--) {
            productArray.push([i * j, i, j]);
        }
    }
    return productArray;
}

var getPalindromeNumberInArray = function getPalindromeNumberInArray(inputArray) {
    /*
    var palindromeArray = [];
    while (item = inputArray.shift()) {
		if (isPalindromeNumber(item)) {
            palindromeArray.push(item);
		}
	}
    return palindromeArray;
    */
    return inputArray.filter(
    function(elem) {
        return isPalindromeNumber(elem[0]);
    });
}

var getLargestValueInArray = function getLargestValueInArray(inputArray) {
    /*
	var largest = 0;
	while (item = inputArray.shift()) {
		if (item > largest) {
			largest = item;
		}
	}
	return largest;
    */
    return inputArray.reduce(
    function(pre, cur) {
        return pre[0] > cur[0] ? pre: cur;
    });
}

//output largest palindrome number
console.log(getLargestValueInArray(getPalindromeNumberInArray(getProductArray(999, 100))));
//or
console.log(
getLargestValueInArray(
getProductArray(999, 100).filter(
function(elem) {
    return isPalindromeNumber(elem);
}))); //906609
//output palindrome array
console.log(getPalindromeNumberInArray(getProductArray(999, 100)));
//or
console.log(
getProductArray(999, 100).filter(
function(elem) {
    return isPalindromeNumber(elem);
})); //Array(1239)

