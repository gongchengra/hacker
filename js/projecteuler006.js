//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=6
var range = function range(start, end, step) {
    var range = [];
    var typeofStart = typeof start;
    var typeofEnd = typeof end;

    if (step === 0) {
        throw TypeError("Step cannot be zero.");
    }

    if (typeofStart == "undefined" || typeofEnd == "undefined") {
        throw TypeError("Must pass start and end arguments.");
    } else if (typeofStart != typeofEnd) {
        throw TypeError("Start and end arguments must be of same type.");
    }

    typeof step == "undefined" && (step = 1);

    if (end < start) {
        step = - step;
    }

    if (typeofStart == "number") {

        while (step > 0 ? end >= start: end <= start) {
            range.push(start);
            start += step;
        }

    } else if (typeofStart == "string") {

        if (start.length != 1 || end.length != 1) {
            throw TypeError("Only strings with one character are supported.");
        }

        start = start.charCodeAt(0);
        end = end.charCodeAt(0);

        while (step > 0 ? end >= start: end <= start) {
            range.push(String.fromCharCode(start));
            start += step;
        }

    } else {
        throw TypeError("Only string and number types are supported");
    }

    return range;

}

var sumOfSquare = function sumOfSquare(inputArray) {
    return inputArray.reduce(function(pre, cur) {
        return pre + cur * cur;
    });
}

var squareOfsum = function squareOfsum(inputArray) {
    var sum = inputArray.reduce(function(pre, cur) {
        return pre + cur;
    });
    return sum * sum;
}

console.log(sumOfSquare(range(1, 10)) - squareOfsum(range(1, 10))); //2640
console.log(sumOfSquare(range(1, 100)) - squareOfsum(range(1, 100))); //25164150 
// smarter way: 
// 1^2+2^2+...+n^2 = (2n+1)*(n+1)*n/6
// 1+2+3+...+n = (n+1)*n/2
var sumOfSquare = function sumOfSquare(N) {
    return (2 * N + 1) * (N + 1) * N / 6;
}

var squareOfsum = function squareOfsum(N) {
    return ((N + 1) * N / 2) * ((N + 1) * N / 2);
}

console.log(sumOfSquare(100) - squareOfsum(100));

