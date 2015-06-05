//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=36
//The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
//
//Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
//
//(Please note that the palindromic number, in either base, may not include leading zeros.)
var isPalindromeNumber = function isPalindromeNumber(N) {
    return (N).toString() === (N).toString().split("").reverse().join("");
}

var sum = 0;
var palinArray = [];
for (var i = 1; i < 1000000; i += 2) {
    if (isPalindromeNumber(i) && isPalindromeNumber(i.toString(2))) {
        sum += i;
        palinArray.push(i);
    }
}
console.log(sum); //872187
console.log(palinArray);//[1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223, 39993, 53235, 53835, 73737, 585585]

