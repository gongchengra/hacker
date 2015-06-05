// author: gongchengra@gmail.com
// http://projecteuler.net/problem=41
// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
//
// What is the largest n-digit pandigital prime that exists?
var getPrimeNumbersLessthanN = function getPrimeNumbersLessthanN(N) {
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

var isPandigital = function isPandigital(N, min, max) {
    var nArray = N.toString().split('');
    if (nArray.length !== (max - min + 1)) {
        return false;
    } else {
        for (var i = min; i <= max; i++) {
            if (nArray.indexOf(i.toString()) === - 1) {
                return false;
            }
        }
        return true;
    }
}

var isPandigitalN = function isPandigitalN(N) {
    var min = 1;
    var max = N.toString().split('').length;
    return (isPandigital(N, min, max));
}

var allPandigital = getPrimeNumbersLessthanN(999999999);
//var allPandigital = getPrimeNumbersLessthanN(99999999);
var largestPandigital = 0;
for (var i = 0; i < allPandigital.length; i++) {
    if (isPandigitalN(allPandigital[i])) {
        largestPandigital = allPandigital[i];
    }
}
console.log(largestPandigital);//7652413

