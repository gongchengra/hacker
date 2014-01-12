//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=24
/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
var factorialArrayLtN = function factorialArrayLtN (N) {
    var facArray = [];
    var intN = parseInt(N);
    if(intN <= 1) {
        return [1];
    } else {
        var product = 1;
        facArray.push(1);
        for(var i=1; i< intN; i++) {
            facArray.push(facArray[i-1]*i);
        }
    }
    return facArray;
}

var dividableByArray = function dividableByArray(N, inputArray) {
    var factorArray = [];
    for(var i = inputArray.length - 1; i >= 0; i--) {
        factorArray.push(parseInt(N/inputArray[i]));
        N %= inputArray[i];
    }
    return factorArray;
}

console.log(factorialArrayLtN(10));
console.log(dividableByArray(999999, factorialArrayLtN(10)));
/*
output:
[1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880] 
[2, 6, 6, 2, 5, 1, 2, 1, 1, 0]
A bit complecated:
Above result means:
999999=2*362880+6*40320+6*5040+2*720+5*120+1*24+2*6+1*2+1*1
Thus, the 1000000 sort should be:
2783915460
*/
