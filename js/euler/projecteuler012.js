//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=12
//The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
//
//1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
//Let us list the factors of the first seven triangle numbers:
//
// 1: 1
//  3: 1,3
//   6: 1,2,3,6
//   10: 1,2,5,10
//   15: 1,3,5,15
//   21: 1,3,7,21
//   28: 1,2,4,7,14,28
//   We can see that 28 is the first triangle number to have over five divisors.
//
//   What is the value of the first triangle number to have over five hundred divisors?
//
var calculateNthTriangleNumber = function calculateNthTriangleNumber(N) {
    return (N + 1) * N / 2;
}

var getDivisorNumberOfN = function getDivisorNumberOfN(N) {
    var divisorNumber = 0;
    var sqrtN = Math.sqrt(N);
    for (var i = 1; i < sqrtN; i++) {
        if (N % i == 0) {
            divisorNumber++;
        }
    }
    divisorNumber *= 2;
    if (N % sqrtN === 0) {
        divisorNumber++;
    }
    return divisorNumber;
}

var getFistTriangleNumberWithNdivisors = function getFistTriangleNumberWithNdivisors(N) {
    var i = 1;
    var iTriangleNumber = 0;
    while (1) {
        //iTriangleNumber = calculateNthTriangleNumber(i);
        //a smarter way, no need to calculate everytime;
        iTriangleNumber += i;
        if (getDivisorNumberOfN(iTriangleNumber) > N) {
            return iTriangleNumber;
        }
        i++;
    }
}

console.log(getDivisorNumberOfN(calculateNthTriangleNumber(5)));
console.log(getFistTriangleNumberWithNdivisors(500)); //76576500 

