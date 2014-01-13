//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=14
/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

var calculateLengthOfCollatzSequence = function calculateLengthOfCollatzSequence(N) {
    var length = 1;
    while (N !== 1) {
        length++;
        if (N % 2 == 0) {
            N = N / 2;
        } else {
            N = N * 3 + 1;
        }
    }
    return length;
};

var getMaxLengthOfCollatzSeqUnderN = function getMaxLengthOfCollatzSeqUnderN(N) {
    var maxLength = 0;
    var maxStartingNumber = 1;
    for (var i = 1; i < N; i++) {
        var iLength = calculateLengthOfCollatzSequence(i);
        if (iLength > maxLength) {
            maxStartingNumber = i;
            maxLength = iLength;
        }
    }
    return maxStartingNumber + ' ' + maxLength;
};

console.log(getMaxLengthOfCollatzSeqUnderN(1000000)) : //837799 525 

