// author: gongchengra@gmail.com
// http://projecteuler.net/problem=38
// Take the number 192 and multiply it by each of 1, 2, and 3:
//
// 192  1 = 192
// 192  2 = 384
// 192  3 = 576
// By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
//
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
//
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n 1?
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

var getProductArray = function getProductArray(a, n) {
    var result = '';
    for (var i = 1; i <= n; i++) {
        result += (i * a).toString();
    }
    return parseInt(result);
}

var getLargestPan = function getLargestPan() {
    var largest = 0;
    var ab = '';
    //for the case n = 2;
    //aaaa+bbbbb
    //so 5000<a<10000
    for (var i = 5001; i < 10000; i++) {
        if (!isUniqNumber(i) || containsZero(i)) {
            continue;
        } else {
            var tmp = getProductArray(i, 2);
            if (isPandigital(tmp, 1, 9) && tmp > largest) {
                largest = tmp;
                ab = i + ' ' + 2;
            }
        }
    }
    //for the case n = 3;
    //aaa+bbb+ccc
    //so 100<a<334
    for (i = 101; i < 334; i++) {
        if (!isUniqNumber(i) || containsZero(i)) {
            continue;
        } else {
            var tmp = getProductArray(i, 3);
            if (isPandigital(tmp, 1, 9) && tmp > largest) {
                largest = tmp;
                ab = i + ' ' + 3;
            }
        }
    }
    //for the case n = 4;
    //aa+bb+cc+ddd
    //so 25<a<34
    for (i = 25; i < 34; i++) {
        if (!isUniqNumber(i) || containsZero(i)) {
            continue;
        } else {
            var tmp = getProductArray(i, 4);
            if (isPandigital(tmp, 1, 9) && tmp > largest) {
                largest = tmp;
                ab = i + ' ' + 4;
            }
        }
    }
    //for the case n = 5;
    //a+bb+cc+dd+ee
    //so 5<a<10
    for (i = 5; i < 10; i++) {
        if (!isUniqNumber(i) || containsZero(i)) {
            continue;
        } else {
            var tmp = getProductArray(i, 5);
            if (isPandigital(tmp, 1, 9) && tmp > largest) {
                largest = tmp;
                ab = i + ' ' + 5;
            }
        }
    }
    return ab + ' ' + largest;
}

console.log(getLargestPan()); //932718654

