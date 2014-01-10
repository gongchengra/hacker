var largestValueInArray = function largestValueInArray(inputArray) {
	return inputArray.reduce(
	function(pre, cur) {
		return pre > cur ? pre: cur;
	});
}

var sumOfValueInArray = function sumOfValueInArray(inputArray) {
	return inputArray.reduce(
	function(pre, cur) {
		return pre + cur;
	});
}

var range = function range(start, end, step) {
	var range = [];
	var typeofStart = typeof start;
	var typeofEnd = typeof end;

	if (step === 0) {
		throw TypeError("Step cannot be zero.");
	}

	if (typeofStart == "undefined" || typeofEnd == "undefined") {
		throw TypeError("Must pass start and end arguments.");
	} else if (typeofStart != typeofEnd) {
		throw TypeError("Start and end arguments must be of same type.");
	}

	typeof step == "undefined" && (step = 1);

	if (end < start) {
		step = - step;
	}

	if (typeofStart == "number") {

		while (step > 0 ? end >= start: end <= start) {
			range.push(start);
			start += step;
		}

	} else if (typeofStart == "string") {

		if (start.length != 1 || end.length != 1) {
			throw TypeError("Only strings with one character are supported.");
		}

		start = start.charCodeAt(0);
		end = end.charCodeAt(0);

		while (step > 0 ? end >= start: end <= start) {
			range.push(String.fromCharCode(start));
			start += step;
		}

	} else {
		throw TypeError("Only string and number types are supported");
	}

	return range;

}

var generateRandomNumberArray = function generateRandomNumberArray(N) {
	var randomArray = [];
	for (var i = 0; i < N; i++) {
		randomArray[i] = Math.floor(Math.random() * N + 1);
	}
	return randomArray;
};

