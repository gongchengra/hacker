//Author: gongchengra@gmail.com
//Solve the problem in http://projecteuler.net/problem=15
/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/

//Get a clue from http://www.robertdickau.com/lattices.html, the number should be C_n_k
//Thus C_40_20
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

var C_n_k = function C_n_k(n, k) {
	return factorialOfN(n) / factorialOfN(k) / factorialOfN(n - k);
}

console.log(C_n_k(40, 20)); //137846528820

