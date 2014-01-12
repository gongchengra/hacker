//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=21
/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

var getSumOfDivisorsOfN = function getSumOfDivisorsOfN(N) {
    var sumDivisor = 1;
    for(var i=2; i*i < N; i++) {
        if(N % i == 0){
            sumDivisor += i;
            sumDivisor += parseInt(N/i);
        }
    }
    if(i*i === N) {
        sumDivisor += i;
    }
    return sumDivisor;
}

var isAmicableNumbers = function isAmicableNumbers(N) {
    return N === getSumOfDivisorsOfN(getSumOfDivisorsOfN(N));
}

var getAmicableNumbersLtN = function getAmicableNumbersLtN(N) {
    var amicableArray = [];
    for(var i = 2; i < N; i++) {
        if(isAmicableNumbers(i) && getSumOfDivisorsOfN(i) != i) {
            amicableArray.push(i);
        }
    }
    return amicableArray;
}

var getSumOfAmicableNumbersLtN = function getSumOfAmicableNumbersLtN(N) {
    var sum = 0;
    for(var i = 2; i < N; i++) {
        if(isAmicableNumbers(i) && getSumOfDivisorsOfN(i) != i) {
            sum += i;
        }
    }
    return sum;
}

console.log(getAmicableNumbersLtN(10000));
console.log(getSumOfAmicableNumbersLtN(10000)); //31626
