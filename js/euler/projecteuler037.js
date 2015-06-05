// author: gongchengra@gmail.com
// http://projecteuler.net/problem=37
// The number 3797 has an interesting property. 
// Being prime itself, it is possible to continuously remove digits from left to right, 
// and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
//
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
//
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
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

var primeArray = getPrimeNumbersLessthanN(1000000);

var isTruncatable = function isTruncatable(N) {
    var nArray = N.toString();
    if (nArray.length < 2) {
        return false;
    } else {
        for (var i = 1; i < nArray.length; i++) {
            var tmp = nArray.substring(i);
            if (primeArray.indexOf(parseInt(tmp)) === - 1) {
                return false;
            }
        }
        for (var j = nArray.length - 1; j > 0; j--) {
            var tmp = nArray.substring(0, j);
            if (primeArray.indexOf(parseInt(tmp)) === - 1) {
                return false;
            }
        }
    }
    return true;
}
//console.log(isTruncatable(3797));
var sumOfValueInArray = function sumOfValueInArray(inputArray) {
    return inputArray.reduce(
    function(pre, cur) {
        return pre + cur;
    });
}

var countTruncatable = 0;
var truncatableArray = [];
for (var j = 0; j < primeArray.length; j++) {
    if (isTruncatable(primeArray[j])) {
        truncatableArray.push(primeArray[j]);
        countTruncatable++;
    }
}

console.log(countTruncatable);//11
console.log(truncatableArray);//[23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397] 
console.log(sumOfValueInArray(truncatableArray));//748317

