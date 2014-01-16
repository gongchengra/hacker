//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=25
/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn1 + Fn2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

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

var getFirstFibNumberWithNDigitals = function getFirstFibNumberWithNDigitals(N) {
    var f1 = 1;
    var f2 = 1;
    for (var i = 3;; i++) {
        var f3 = sumOfLargeNumbers(f1, f2);
        if (f3.length >= N) {
            return i + ' ' + f3;
        }
        f1 = f2;
        f2 = f3;
    }
}

console.log(getFirstFibNumberWithNDigitals(N));
//4782 1070066266382758936764980584457396885083683896632151665013235203375314520604694040621889147582489792657804694888177591957484336466672569959512996030461262748092482186144069433051234774442750273781753087579391666192149259186759553966422837148943113074699503439547001985432609723067290192870526447243726117715821825548491120525013201478612965931381792235559657452039506137551467837543229119602129934048260706175397706847068202895486902666185435124521900369480641357447470911707619766945691070098024393439617474103736912503231365532164773697023167755051595173518460579954919410967778373229665796581646513903488154256310184224190259846088000110186255550245493937113651657039447629584714548523425950428582425306083544435428212611008992863795048006894330309773217834864543113205765659868456288616808718693835297350643986297640660000723562917905207051164077614812491885830945940566688339109350944456576357666151619317753792891661581327159616877487983821820492520348473874384736771934512787029218636250627816
