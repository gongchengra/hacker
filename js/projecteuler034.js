// author: gongchengra@gmail.com
// http://projecteuler.net/problem=34
// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.
//
// Note: as 1! = 1 and 2! = 2 are not sums they are not included.
//
// 9 326800
// 99 326800*2
// 999 326800*3
// 9999 326800*4
// 99999 326800*5
// 999999 326800*6
// 9999999 326800*7
// 326800*n < n*10^n
// n > log(326800) = 5.5142
var log10 = function log10(val) {
  return Math.log(val) / Math.LN10;
}
//console.log(log10(326800)); //5.5142

var factorialOfN = function factorialOfN(N) {
    var intN = parseInt(N);
    if (intN <= 1) {
        return 1;
    } else {
        var product = 1;
        for (var i = 2; i <= intN; i++) {
            product *= i;
        }
        return product;
    }
}

var sumOfDigitalFactorial = function sumOfDigitalFactorial(N) {
    var digitalArray = N.toString().split('');
    return digitalArray.reduce(
    function(pre, cur) {
        return pre +factorialOfN(cur);
    },0);
}

var sumCuriousNumber = function sumCuriousNumber(){
    var sum = 0;
    for(var i =10; i< 326800*7; i++) {
        if(sumOfDigitalFactorial(i) === i) {
            sum += i;
            console.log(i);
        }
    }
    return sum;
}

console.log(sumCuriousNumber());
//output
//145
//40585
//40730
