// author: gongchengra@gmail.com
// http://projecteuler.net/problem=27
// Euler discovered the remarkable quadratic formula:
//
// n² + n + 41
//
// It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
// However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
//
// The incredible formula  n²  79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. 
// The product of the coefficients, 79 and 1601, is 126479.
//
// Considering quadratics of the form:
//
// n² + an + b, where |a|  1000 and |b|  1000
//
// where |n| is the modulus/absolute value of n
// e.g. |11| = 11 and |4| = 4
// Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
//
// when n = 0, formula becomes b, so b must be a prime.
// when n = 1, formula becomes 1+a+b, so it must be a prime.

var getPrimeNumbersLessthanN = function(N) {
    var primeArray = new Int8Array(N);
    for (var i = 0; i < primeArray.length; i++) {
        primeArray[i] = 0;
    }
    for (var i = 0; i <= Math.sqrt(N); i++) {
        if (primeArray[i] === 0) {
            var tmp = i + 2;
            for (var j = i + tmp; j < primeArray.length; j += tmp) {
                primeArray[j] = 1;
            }
        }
    }
    var resultArray = [];
    for (var i = 0; i < primeArray.length; i++) {
        if (primeArray[i] === 0 && (i + 2 < N)) {
            resultArray.push(i + 2);
        }
    }
    return resultArray;
}

var primeArray = getPrimeNumbersLessthanN(1000 * 1000 * 2 + 1000);
var bArray = getPrimeNumbersLessthanN(1000);
var maxPrime = 2;
var tmpPrime = 0;
var tmpA = 0;
var tmpB = 0;
for (var a = - 999; a < 1000; a++) {
    for (var b = 0; b < bArray.length; b++) {
        var bVal = bArray[b];
        var i = 0;
        if (i * i + a * i + bVal > 0 && primeArray.indexOf(1 + a + bVal) !== - 1) {
            do {
                var formula = i * i + a * i + bVal;
                i++;
            } while (primeArray.indexOf(formula) !== - 1);
            //            console.log(a + ' ' + bVal + ' ' + ' ' + i + ' ' + formula);
            if (i > 1) {
                tmpPrime = (i - 2) * (i - 2) + a * (i - 2) + bVal;
                //               console.log(tmpPrime);
                if ((primeArray.indexOf(tmpPrime) !== - 1) && (tmpPrime > maxPrime)) {
                    maxPrime = tmpPrime;
                    tmpA = a;
                    tmpB = bVal;
                    //                    console.log(a + ' ' + b);
                }
            }
        }
    }
}

console.log(tmpA + ' ' + tmpB);

// easier to understand.
var isPrime = function isPrime(N) {
    if (N < 2) {
        return false;
    }
    for (var i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

var countMaxPrimes = function countMaxPrimes(a, b) {
    var c = 0;
    for (var n = 0;; n++) {
        var p = n * (n + a) + b;
        if (!isPrime(p)) break;
        c++;
    }
    return c;
}

var m = 0;
var ma, mb;

for (var a = - 999; a <= 999; a++)
for (var b = 2; b <= 999; b++) {
    if(isPrime(b)){
        var c = countMaxPrimes(a, b);
        if (c > m) {
            m = c;
            ma = a;
            mb = b;
        }
    }
}

console.log(ma + ' ' + mb);

