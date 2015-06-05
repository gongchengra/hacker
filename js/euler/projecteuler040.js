// author: gongchengra@gmail.com
// http://projecteuler.net/problem=40
// An irrational decimal fraction is created by concatenating the positive integers:
//
// 0.123456789101112131415161718192021...
//
// It can be seen that the 12th digit of the fractional part is 1.
//
// If dn represents the nth digit of the fractional part, find the value of the following expression.
//
// d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000
// d1 = 1
// d1-d9 = 1-9
// d10-d(10+2*99) = if(n%2 == 0) (n-9)
var darray = function darray(N) {
    var result_array = [];
    for (var i = 1; result_array.length <= N; i++) {
        var iarray = i.toString().split("");
        var item;
        while (item = iarray.shift()) {
            result_array.push(item);
        }
    }
    return result_array;
}

var d = darray(1000000);
console.log((d[0]) * (d[9]) * (d[99]) * (d[999]) * (d[9999]) * (d[99999]) * (d[999999]));//210

