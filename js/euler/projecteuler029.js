// author: gongchengra@gmail.com
// http://projecteuler.net/problem=29
// Consider all integer combinations of ab for 2  a  5 and 2  b  5:
//
// 2^2=4, 2^3=8, 2^4=16, 2^5=32
// 3^2=9, 3^3=27, 3^4=81, 3^5=243
// 4^2=16, 4^3=64, 4^4=256, 4^5=1024
// 5^2=25, 5^3=125, 5^4=625, 5^5=3125
// If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
//
// 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
//
// How many distinct terms are in the sequence generated by ab for 2 <= a <= 100 and 2 <= b <= 100?
var isPrime = function isPrime(N) {
    if (N < 2) {
        return false;
    }
    for (var i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

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

function f(a, b) {
    return a - b;
}

var getPrimeFactorArrayAll = function getPrimeFactorArrayAll(N) {
    var factorArray = [];
    var primeArray = getPrimeNumbersLessthanN(N + 1);
    while (N !== 1) {
        for (var i = 0; i < primeArray.length; i++) {
            if (N % primeArray[i] == 0) {
                factorArray.push(primeArray[i]);
                N = N / primeArray[i];
            }
        }
    }
    return factorArray.sort(f);
}

var distinctPower = function distinctPower(a, b) {
    if (isPrime(a)) {
        return a + '^' + b + ';';
    } else {
        var primeArray = getPrimeFactorArrayAll(a);
        var bStr = '';
        var tmpIndex = b;
        for (var i = 0; i < primeArray.length-1; i++) {
            if (primeArray[i] !== primeArray[i + 1]) {
                bStr += primeArray[i] + '^' + tmpIndex + ';';
                tmpIndex = b;
            } else {
                tmpIndex += b;
            }
        }
        bStr += primeArray[i] + '^' + tmpIndex + ';';
        return bStr;
    }
}

var powerSequence = function powerSequence() {
    var distinctTerms = [];
    for(var a = 2; a <= 100; a++) {
        for(var b = 2; b <= 100; b++){
            var term = distinctPower(a,b);
            if(distinctTerms.indexOf(term) === -1) {
                distinctTerms.push(term);
            }
        }
    }
    return distinctTerms.length;
}

console.log(powerSequence());//9183

