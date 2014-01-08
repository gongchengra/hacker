//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=9
//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//a^2 + b^2 = c^2
//For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

var findTriplet = function findTriplet(N) {
    var a;
    var b;
    var c;
    for(a = 1; a < N/3; a++){
        for(b = a+1; b < N/2; b++){
            c = N - a - b;
            if(c < b || (c*c !== a*a + b*b)) {
                continue;
            } else {
                return a + ' ' + b + ' ' + c + ' ' + a*b*c;
            }
        }
    }
};

var findGCD = function findGCD(a,b){
    var tmp = 0;
    while(b !== 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

//console.log(findTriplet(1000)); //200 375 425 31875000 
var findTripletLessThanN = function findTripletLessThanN(N) {
    var tripletArrayAll = [];
    for(var i = 3; i < N; i++) {
        if(findTriplet(i) !== undefined) {
            var tripletString = findTriplet(i);
            var tripletArray = tripletString.split(' ');
            var GCDofArray = findGCD(parseInt(tripletArray[0]),parseInt(tripletArray[1]));
            if(GCDofArray === 1){
                tripletArrayAll.push(tripletString);
            } else {
                tripletArray[0] /= GCDofArray;
                tripletArray[1] /= GCDofArray;
                tripletArray[2] /= GCDofArray;
                tripletArray[3] /= (GCDofArray*GCDofArray*GCDofArray);
                tripletString = tripletArray[0] + ' ' + tripletArray[1] + ' ' + tripletArray[2] + ' ' + tripletArray[3];
                if(tripletArrayAll.indexOf(tripletString) === -1) {
                    tripletArrayAll.push(tripletString);
                }
            }
        }
    }
    return tripletArrayAll;
}

console.log(findTripletLessThanN(100));
