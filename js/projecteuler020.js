//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=20
/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/


var productOfLargeNumbers = function productOfLargeNumbers(multiplier, multiplicand ) {
    var multiplierArray = multiplier.toString().split("");
    var multiplicandArray  = multiplicand.toString().split("");
    var lenMultiplier = multiplierArray.length;
    var lenMultiplicand = multiplicandArray.length;
    var resultArray = [];
    for(var i = 0; i < lenMultiplier; i++){
        for(var j= 0; j < lenMultiplicand; j++){
            if(resultArray[i+j] === undefined) {
                resultArray[i+j] = 0;
            }
            resultArray[i+j] += multiplierArray[i]*multiplicandArray[j];
        }
    }
    for(var k = resultArray.length; k > 0; k--) {
        if(resultArray[k]>9) {
            resultArray[k-1] += parseInt(resultArray[k]/10);
            resultArray[k] = resultArray[k]%10;
        }
    }
    resultArray0 = resultArray[0];
    if(resultArray0 > 9) {
        resultArray[0] %= 10;
        while(resultArray0 !== 0) {
            resultArray0 = parseInt(resultArray0/10);
            resultArray.unshift(resultArray0%10);
        }
    }
    return resultArray.join("");
}

var factorialOfN = function factorialOfN (N) {
    var intN = parseInt(N);
    if(intN <= 1) {
        return 1;
    } else {
        var product = "1";
        for(var i=2; i<= intN; i++) {
            product = productOfLargeNumbers(product, i);
        }
        return product;
    }
}

var sumOfValueInArray = function sumOfValueInArray(inputArray) {
        return inputArray.reduce(
        function(pre, cur) {
                return parseInt(pre) + parseInt(cur);
        });
}

console.log(sumOfValueInArray(factorialOfN(100).split(""))); //648 
