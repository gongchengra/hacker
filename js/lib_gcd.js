var findGCD = function findGCD(a, b) {
	var tmp = 0;
	while (b !== 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

