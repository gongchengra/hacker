// author: gongchengra@gmail.com
// http://projecteuler.net/problem=32
// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
//
// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
//
// Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
//
// HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
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

var isUniqNumber = function isUniqNumber(N) {
    var nArray = N.toString().split('');
    return nArray.toString() === nArray.filter(function(e, i, arr) {
        return arr.lastIndexOf(e) === i;
    }).toString();
}

var containsZero = function containsZero(N) {
    var nArray = N.toString().split('');
    return nArray.indexOf('0') !== - 1;
}

var getPandigitalArray = function getPandigitalArray() {
    var max = 987654321;
    var sqrtMax = Math.sqrt(max);
    var resultArray = [];
    var sum = 0;
    for (var i = 2; i <= sqrtMax; i++) {
        if (!isUniqNumber(i) || containsZero(i)) {
            continue;
        }
        for (var j = i + 1; i * j <= max; j++) {
            if (!isUniqNumber(j) || containsZero(j)) {
                continue;
            }
            if (isUniqNumber(i * j)) {
                var tmpStr = i.toString().concat(j.toString()).concat((i * j).toString());
                console.log(i + ' ' + j);
                if (tmpStr.length === 9) {
                    console.log(tmpStr);
                    //                    console.log(isPandigital(tmpStr, 1, 9));
                    if (isPandigital(tmpStr, 1, 9)) {
                        resultArray.push(i + ' ' + j + ' ' + i * j);
                        console.log(i + ' ' + j + ' ' + i * j);
                    }
                }
            }
        }
    }
    return resultArray;
}

console.log(getPandigitalArray());

