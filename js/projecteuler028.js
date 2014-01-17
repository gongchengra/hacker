// author: gongchengra@gmail.com
// http://projecteuler.net/problem=28
/*
* Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
*
* 21 22 23 24 25
* 20  7  8  9 10
* 19  6  1  2 11
* 18  5  4  3 12
* 17 16 15 14 13
*
* It can be verified that the sum of the numbers on the diagonals is 101.
*
* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/
var getSpiralArray = function getSpiralArray(N) {
    var a = [];
    a[0] = 1;
    var noN = 1 + (N-1)*2;
    for(var i = 1; i< noN; i++) {
        a[i] = a[i-1] + Math.ceil(parseInt((i+3)/4))*2;
    }
    return a;
}

var sumOfValueInArray = function sumOfValueInArray(inputArray) {
    return inputArray.reduce(
    function(pre, cur) {
        return pre + cur;
    });
}

console.log(sumOfValueInArray(getSpiralArray(1001))); //669171001

