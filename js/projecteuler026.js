//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=26
/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2= 0.5
1/3= 0.(3)
1/4= 0.25
1/5= 0.2
1/6= 0.1(6)
1/7= 0.(142857)
1/8= 0.125
1/9= 0.(1)
1/10= 0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/
var fractionArray = function fractionArray(N) {
    var resultArray = [];
    var dividendArray = [];
    var dividend = 1;
    var divisor = N;
    for (var i = 0;; i++) {
        resultArray.push(parseInt(dividend / divisor));
        if (dividend == 0) {
            return resultArray;
        }
        dividend = (dividend % divisor) * 10;
        if (dividendArray.indexOf(dividend) === - 1) {
            dividendArray.push(dividend);
        } else {
            //console.log(dividendArray.pop());
            while (dividendArray.pop() !== undefined) {
                resultArray.push(parseInt(dividend / divisor));
                dividend = (dividend % divisor) * 10;
            }
            return resultArray;
        }
    }
}

var fractionCycleLength = function fractionCycleLength(N) {
    var resultArray = [];
    var dividendArray = [];
    var dividend = 1;
    var divisor = N;
    for (var i = 0;; i++) {
        //console.log(dividend);
        resultArray.push(parseInt(dividend / divisor));
        if (dividend === 0) {
            return 0;
        }
        dividend = (dividend % divisor) * 10;
        if (dividendArray.indexOf(dividend) === -1) {
            dividendArray.push(dividend);
        } else {
            var lenAll = dividendArray.length;
            for (var j = 0; j < lenAll; j++) {
                if (dividendArray.indexOf(dividend) !== -1) {
                    dividendArray.splice(dividendArray.indexOf(dividend), 1);
                }
                dividend = (dividend % divisor) * 10;
            }
            var lenOri = dividendArray.length;
            return lenAll - lenOri;
        }
    }
}

var getMaxCycleLengthLtN = function getMaxCycleLengthLtN(N) {
    var maxI = 2;
    var maxLen = 0;
    for (var i = 2; i < N; i++) {
        var iLen = fractionCycleLength(i);
        if (iLen > maxLen) {
            maxI = i;
            maxLen = iLen;
        }
    }
    return maxI + ' ' + maxLen;
}

console.log(getMaxCycleLengthLtN(1000)); //983 982

