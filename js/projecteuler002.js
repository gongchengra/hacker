// author: gongchengra@gmail.com
// http://projecteuler.net/problem=2
var fibArrayLessThanN = function fibArrayLessThanN(N) {
	var i = 0;
	var fib_array = [];
	fib_array[0] = 1;
	fib_array[1] = 2;
	for (i = 0; fib_array[i] < N; i++) {
		if (fib_array[i + 1] > N) {
			return fib_array;
		}
		fib_array[i + 2] = fib_array[i] + fib_array[i + 1];
	}
}

var sumOfEvenValueInArray = function sumOfEvenValueInArray(inputArray) {
	var sum = 0;
	while (item = inputArray.shift()) {
		if (item % 2 == 0) {
			sum += item;
		}
	}
	return sum;
}

console.log(sumOfEvenValueInArray(fibArrayLessThanN(4000000))); //4613732

// smarter way, every third number is even
// 1. use reduce
console.log(fibArrayLessThanN(4000000).reduce(
function(pre, cur, idx) {
	return pre + ((idx % 3 == 1) ? cur: 0);
}, 0));

// 2. expand 1, this equivalent to 1, but easier to read.
var sumOfEvenValueInFabnacciArray = function sumOfEvenValueInFabnacciArray(inputArray) {
	var sum = 0;
	var inputArrayLength = inputArray.length;
	for (var i = 0; i < inputArrayLength; i++) {
		if (i % 3 == 1) {
			sum += inputArray[i];
		}
	}
	return sum;
}

console.log(sumOfEvenValueInFabnacciArray(fibArrayLessThanN(4000000)));

var sumOfEvenValueInFibnacci = function sumOfEvenValueInFibnacci(N) {
	var sum = 0;
	var a = 1;
	var b = 1;
	var c = a + b;
	while (c < N) {
		sum += c;
		a = b + c;
		b = c + a;
		c = a + b;
	}
	return sum;
}

console.log(sumOfEvenValueInFibnacci(4000000));

