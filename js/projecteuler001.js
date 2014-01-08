// author: gongchengra@gmail.com
// http://projecteuler.net/problem=1

// easiest way
var sum = function(N) {
	var multiple = 0;
	for (var i = 1; i < N; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			multiple += i;
		}
	}
	return multiple;
}
console.log(sum(1000));

// smarter way
var sumOfNumberLessThanMaxAndDivisibeByN = function sumOfNumberLessThanMaxAndDivisibeByN(Max, N) {
    var pMax = parseInt(Max/N);
    return N*pMax*(pMax+1)/2;
}

console.log(
    sumOfNumberLessThanMaxAndDivisibeByN(999,3)+sumOfNumberLessThanMaxAndDivisibeByN(999,5)-sumOfNumberLessThanMaxAndDivisibeByN(999,15));
