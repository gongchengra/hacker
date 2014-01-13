// author: gongchengra@gmail.com
// http://projecteuler.net/problem=3
var getPrimeNumbersLessthanN = function(N) {
    var primeArray = new Int8Array(N);
    for (var i = 0; i < primeArray.length; i++) {
        primeArray[i] = 0;
    }
    for (var i = 0; i <= Math.sqrt(N); i++) {
        if (primeArray[i] === 0) {
            for (var j = i + 2; j < primeArray.length; j++) {
                if ((j + 2) % (i + 2) === 0) {
                    primeArray[j] = 1;
                }
            }
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

//this function only works when all the factors of N are smaller than sqrt(N).
var getPrimeFactorArray = function getPrimeFactorArray(N) {
    var factorArray = [];
    var primeArray = getPrimeNumbersLessthanN(Math.sqrt(N + 1));
    for (var i = 0; i < primeArray.length; i++) {
        if (N % primeArray[i] == 0) {
            factorArray.push(primeArray[i]);
            N = N / primeArray[i];
            i = 0;
        }
    }
    return factorArray;
}

//correct getPrimeFactorArray should be the following one:
//however this one is much slower.
var getPrimeFactorArray = function getPrimeFactorArray(N) {
    var factorArray = [];
    var primeArray = getPrimeNumbersLessthanN(N + 1);
    for (var i = 0; i < primeArray.length; i++) {
        if (N % primeArray[i] == 0) {
            factorArray.push(primeArray[i]);
            N = N / primeArray[i];
        }
    }
    return factorArray;
}

var getLargestValueInArray = function getLargestValueInArray(inputArray) {
    var largest = 0;
    while (item = inputArray.shift()) {
        if (item > largest) {
            largest = item;
        }
    }
    return largest;
}
console.log(getPrimeFactorArray(600851475143));
console.log(getLargestValueInArray(getPrimeFactorArray(600851475143))); //6857

