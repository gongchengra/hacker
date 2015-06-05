//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=7
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
//What is the 10 001st prime number?
var getFirstNPrimeNumbers = function(N) {
    var resultArray = [];
    var intN = parseInt(N);
    if (intN < 1) {
        resultArray[0] = 'Invalid argument.';
    } else if (intN == 1) {
        resultArray[0] = '2';
    } else {
        //According to Prime_number_theorem,
        //the N prime number is approximately N*ln(N),
        //in order to make sure we can get N numbers, we multiply by a factor 1.2
        if (intN < 20) {
            var maxNumber = Math.ceil(3 * intN * Math.log(intN));
        } else {
            var maxNumber = Math.ceil(1.2 * intN * Math.log(intN));
        }
        var primeArray = new Int8Array(maxNumber);
        for (var i = 0; i < primeArray.length; i++) {
            primeArray[i] = 0;
        }
        var sqrtMax = Math.sqrt(maxNumber);
        for (var i = 0; i <= sqrtMax; i++) {
            if (primeArray[i] === 0) {
                for (var j = i + 2; j < maxNumber; j++) {
                    if ((j + 2) % (i + 2) === 0) {
                        primeArray[j] = 1;
                    }
                }
            }
        }
        for (var i = 0; i < primeArray.length, resultArray.length < intN; i++) {
            if (primeArray[i] === 0) {
                resultArray.push(i + 2);
            }
        }
    }
    return resultArray;
}

console.log(getFirstNPrimeNumbers(10001)[10000]); //104743 

