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

var calculateNthPrimeNumber = function(N) {
    var intN = parseInt(N);
    var maxNumber = Math.ceil(intN * Math.log(intN));
    console.log(maxNumber);
    console.log(getPrimeNumbersLessthanN(maxNumber).length);
}

var getFirstNPrimeNumbers = function(N) {
    var resultArray = [];
    var intN = parseInt(N);
    if (intN < 1) {
        resultArray[0] = 'Invalid argument.';
    } else if (intN == 1) {
        resultArray[0] = '2';
    } else {
        //According to Prime_number_theorem,
        //the N prime number is approximately N*ln(N),
        //in order to make sure we can get N numbers, we multiply by a factor 1.2
        if (intN < 20) {
            var maxNumber = Math.ceil(3 * intN * Math.log(intN));
        } else {
            var maxNumber = Math.ceil(1.2 * intN * Math.log(intN));
        }
        var primeArray = new Int8Array(maxNumber);
        for (var i = 0; i < primeArray.length; i++) {
            primeArray[i] = 0;
        }
        var sqrtMax = Math.sqrt(maxNumber);
        for (var i = 0; i <= sqrtMax; i++) {
            if (primeArray[i] === 0) {
                var tmp = i + 2;
                for (var j = i + tmp; j < primeArray.length; j += tmp) {
                    primeArray[j] = 1;
                }
            }
        }
        for (var i = 0; i < primeArray.length, resultArray.length < intN; i++) {
            if (primeArray[i] === 0) {
                resultArray.push(i + 2);
            }
        }
    }
    return resultArray;
}

var getPrimeFactorArray = function getPrimeFactorArray(N) {
    var factorArray = [];
    var primeArray = getPrimeNumbersLessthanN(N + 1);
    for (var i = 0; i < primeArray.length; i++) {
        if (N % primeArray[i] == 0) {
            factorArray.push(primeArray[i]);
            N = N / primeArray[i];
        }
    }
    return factorArray;
}

function f(a, b) {
    return a - b;
}

var getPrimeFactorArrayAll = function getPrimeFactorArrayAll(N) {
    var factorArray = [];
    var primeArray = getPrimeNumbersLessthanN(N + 1);
    while (N !== 1) {
        for (var i = 0; i < primeArray.length; i++) {
            if (N % primeArray[i] == 0) {
                factorArray.push(primeArray[i]);
                N = N / primeArray[i];
            }
        }
    }
    return factorArray.sort(f);
}


