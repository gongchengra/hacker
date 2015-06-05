// author: gongchengra@gmail.com
// http://projecteuler.net/problem=39
/*
 If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}
 , there are exactly three solutions for p = 120.
 
 {20,48,52}, {24,45,51}, {30,40,50}
 
 For which value of p  1000, is the number of solutions maximised?*/

var isTriangle = function isTriangle(a, b, c) {
    return a * a + b * b === c * c;
}

var getTriangleNumber = function getTriangleNumber(N) {
    var number = 0;
    for (var i = 1; i <= N / 3; i++) {
        for (var j = i; j <= N / 2; j++) {
            if (isTriangle(i, j, (N - i - j))) {
                number++;
            }
        }
    }
    return number;
}

var getLargestTriangleNumberLtN = function getLargestTriangleNumberLtN(N) {
    var maxVal = 0;
    var maxNum = 0;
    for (var i = 3; i < N; i++) {
        var triangleNumber = getTriangleNumber(i);
        if (triangleNumber > maxNum) {
            maxVal = i;
            maxNum = triangleNumber;
        }
    }
    return maxVal + ' ' + maxNum;
}

console.log(getLargestTriangleNumberLtN(1001));//840 8

