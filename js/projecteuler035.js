// author: gongchengra@gmail.com
// http://projecteuler.net/problem=35
// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
//
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
//
// How many circular primes are there below one million?
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

var isCircular = function isCircular(N) {
    var nArray = N.toString().split('');
    for (var i = 0; i < nArray.length; i++) {
        if (nArray[i] % 2 === 0) {
            return false;
        }
    }
    for (i = 0; i < nArray.length; i++) {
        nArray.unshift(nArray.pop());
        var tmp = parseInt(nArray.join(''));
        if (primeArray.indexOf(tmp) === - 1) {
            return false;
        }
    }
    return true;
}

var countCircular = 1;
var circularArray = [];
circularArray.push(2);
for (var j = 0; j < primeArray.length; j++) {
    if (isCircular(primeArray[j])) {
        circularArray.push(primeArray[j]);
        countCircular++;
    }
}

console.log(countCircular);//55
console.log(circularArray);//[2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331]

