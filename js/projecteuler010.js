//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=10
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
//Find the sum of all the primes below two million.
var getPrimeNumbersLessthanN = function(N) {
    var primeArray = new Int8Array(N);
    for (var i = 0; i < primeArray.length; i++) {
        primeArray[i] = 0;
    }
    for (var i = 0; i <= Math.sqrt(N); i++) {
        if (primeArray[i] === 0) {
            var tmp = i + 2;
            for (var j = i + tmp; j < primeArray.length; j += tmp) {
                primeArray[j] = 1;
            }
            tmp = 0;
        }
    }
    var resultArray = [];
    for (var i = 0; i < primeArray.length; i++) {
        if (primeArray[i] === 0 && (i + 2 < N)) {
            resultArray.push(i + 2);
        }
    }
    return resultArray;
}

var sumOfValueInArray = function sumOfValueInArray(inputArray) {
    return inputArray.reduce(
    function(pre, cur) {
        return pre + cur;
    });
}

console.log(sumOfValueInArray(getPrimeNumbersLessthanN(2000000)));

