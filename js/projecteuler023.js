//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=23
/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
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

var getAbundantNumbersLtN = function getAbundantNumbersLtN(N) {
    var abundantArray = [];
    for(var i = 1; i < N; i++) {
        if(getSumOfDivisorsOfN(i) > i) {
            abundantArray.push(i);
        }
    }
    return abundantArray;
} 

var abundantArray = getAbundantNumbersLtN(28123);

var dividableBy2AbundantNo = function dividableBy2AbundantNo(N) {
    for(var i = 0; i < abundantArray.length; i++) {
        if(abundantArray[i] < N) {
            if(abundantArray.indexOf(N-abundantArray[i]) !== -1){
                return true; 
            }
        }
    }
    return false;
}

var sumOfUndividableNumberLtN = function sumOfUndividableNumberLtN(N){
    var sum = 0;
    for (var i = 1; i< N; i++) {
        if(dividableBy2AbundantNo(i) === false) {
            sum += i;
        }
    }
    return sum;
}

console.log(sumOfUndividableNumberLtN(28124)); //4179871 
