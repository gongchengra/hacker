//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=4

var isPalindromeNumber = function isPalindromeNumber(N) {
	return (N).toString() === (N).toString().split("").reverse().join("");
}

var getProductArray = function getProductArray(Max, Min) {
	var productArray = [];
	var i;
	for(i=Max;i>=Min;i--){
		for(j=i;j>=Min;j--){
			productArray.push(i*j);
		}
	}
	return productArray;
}

var getLargestValueInArray = function getLargestValueInArray(inputArray) {
	var largest = 0;
    while (item = inputArray.shift()) {
        if(item > largest) {
            largest = item;
        }
    }
    return largest;
}

console.log(
	getLargestValueInArray(
		getProductArray(999,100).filter(
			function(elem){
				return isPalindromeNumber(elem);
				}
			)
		)
	); //906609

console.log(
	getProductArray(999,100).filter(
			function(elem){
				return isPalindromeNumber(elem);
			}
		)
	); //Array(1239)
