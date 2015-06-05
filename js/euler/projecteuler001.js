// author: gongchengra@gmail.com
// http://projecteuler.net/problem=1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, 
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
// easiest way
var sum = function sum(N) {
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
    var pMax = parseInt(Max / N);
    return N * pMax * (pMax + 1) / 2;
}

console.log(
sumOfNumberLessThanMaxAndDivisibeByN(999, 3) + sumOfNumberLessThanMaxAndDivisibeByN(999, 5) - sumOfNumberLessThanMaxAndDivisibeByN(999, 15));

