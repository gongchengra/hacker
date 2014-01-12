//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=16
/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

var pow2toN = function pow2toN (N) {
    var resultArray = [];
    for(var i = 0; i< N-1; i++){
        resultArray[i] = 0;
    }
    resultArray[N-1] = 1;
    for(var j = 0; j < N; j++) {
        for(i = 0; i< N; i++) {
            if(resultArray[i] !== 0) {
                resultArray[i] *= 2;
                if(resultArray[i] > 9) {
                    resultArray[i-1]++;
                    resultArray[i] %= 10;
                }
            }
        }
    }
    return resultArray;
};

var sumOfValueInArray = function sumOfValueInArray(inputArray) {
        return inputArray.reduce(
        function(pre, cur) {
                return pre + cur;
        });
}

console.log(sumOfValueInArray(pow2toN(1000))); //1366
