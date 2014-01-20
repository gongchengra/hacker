var sumOf1toN = function sumOf1toN(N) {
    return N * (N + 1) / 2;
}

var sumOf1squareToNsquare = function sumOf1squareToNsquare(N) {
    return (2 * N + 1) * (N + 1) * N / 6;
}

var sumOfLargeNumbers = function sumOfLargeNumbers(a, b) {
    var inputArray = [];
    inputArray.push(a.toString());
    inputArray.push(b.toString());
    var resultArray = [];
    var maxLength = 0;
    inputArray.forEach(function(elem, index, array) {
        if (elem.length > maxLength) {
            maxLength = elem.length;
        }
    });
    var carryIn = 0;
    for (var i = 0; i < maxLength; i++) {
        var sumOfIthDigital = 0;
        inputArray.forEach(function(elem, index, array) {
            var elemLength = elem.length;
            if (i < elemLength) {
                sumOfIthDigital += parseInt(elem.substring(elemLength - i - 1, elemLength - i));
            }
        });
        sumOfIthDigital += carryIn;
        resultArray.unshift(sumOfIthDigital % 10);
        carryIn = parseInt(sumOfIthDigital / 10);
    }
    resultArray0 = carryIn;
    if (resultArray0 > 9) {
        resultArray[0] %= 10;
        while (resultArray0 !== 0) {
            resultArray.unshift(resultArray0 % 10);
            resultArray0 = parseInt(resultArray0 / 10);
        }
    } else if (resultArray0 > 0) {
        resultArray.unshift(resultArray0);
    }
    return resultArray.join("");
}

var productOfLargeNumbers = function productOfLargeNumbers(multiplier, multiplicand) {
    var multiplierArray = multiplier.toString().split("");
    var multiplicandArray = multiplicand.toString().split("");
    var lenMultiplier = multiplierArray.length;
    var lenMultiplicand = multiplicandArray.length;
    var resultArray = [];
    for (var i = 0; i < lenMultiplier; i++) {
        for (var j = 0; j < lenMultiplicand; j++) {
            if (resultArray[i + j] === undefined) {
                resultArray[i + j] = 0;
            }
            resultArray[i + j] += multiplierArray[i] * multiplicandArray[j];
        }
    }
    for (var k = resultArray.length; k > 0; k--) {
        if (resultArray[k] > 9) {
            resultArray[k - 1] += parseInt(resultArray[k] / 10);
            resultArray[k] = resultArray[k] % 10;
        }
    }
    resultArray0 = resultArray[0];
    if (resultArray0 > 9) {
        resultArray[0] %= 10;
        while (resultArray0 !== 0) {
            resultArray.unshift(resultArray0 % 10);
            resultArray0 = parseInt(resultArray0 / 10);
        }
    }
    return resultArray.join("");
}

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

var fib = function fib(num) {
    if (num > 2) {
        return fib(num - 2) + fib(num - 1);
    } else {
        return 1;
    }
};

var fib_iter = function fib_iter(num) {
    if (num < 2) {
        return num;
    } else {
        var i = 1;
        var sum = 0;
        while (i <= num) {
            f1 = fib_iter(i - 2);
            f2 = fib_iter(i - 1);
            sum = f1 + f2;
            f1 = f2;
            f2 = sum;
            i++;
        }
        return sum;
    }
};

var findGCD = function findGCD(a, b) {
    var tmp = 0;
    while (b !== 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

var log10 = function log10(val) {
  return Math.log(val) / Math.LN10;
}
