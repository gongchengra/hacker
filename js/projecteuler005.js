var getPrimeNumbersLessthanN = function(N) {
	var primeArray = new Int8Array(N);
	for (var i=0; i<primeArray.length; i++) {
	  primeArray[i] = 0;
	}
	for(var i=0;i<=Math.sqrt(N);i++) {
		if(primeArray[i] === 0) {
			for(var j=i+2;j<primeArray.length;j++) {
				if((j+2)%(i+2) === 0) {
					primeArray[j] = 1;
				}
			}
		}
	}
	var resultArray = [];
	for(var i=0;i<primeArray.length;i++) {
		if(primeArray[i] === 0 && (i+2 < N)) {
			resultArray.push(i+2);
		}
	}
	return resultArray;
}

function f(a,b){
    return a-b;
}

var getPrimeFactorArray = function getPrimeFactorArray(N) {
	var factorArray = [];
	var primeArray = getPrimeNumbersLessthanN(N+1);
	while(N !== 1) {
		for(var i=0;i<primeArray.length;i++) {
			if(N%primeArray[i] == 0){
				factorArray.push(primeArray[i]);
				N = N/primeArray[i];
			}
		}
	}
	return factorArray.sort(f);
}

//console.log(getPrimeFactorArray(4));

var arrayCount = function arrayCount(inputArray) {
	var resultArray = [];
	for(var i = 0; i< inputArray.length; i++) {
		if(resultArray.indexOf(inputArray[i]) === -1){
			resultArray[inputArray[i]] = 1;
		} else {
			resultArray[inputArray[i]] += 1;
		}
	}
	return resultArray;
}

console.log(arrayCount(getPrimeFactorArray(4)));

var factorArrayToObject = function factorArrayToObject(inputArray) {
	var factorObject = {};
	while (item = inputArray.shift()) {
	    if(item in factorObject) {
	    	factorObject[item] += 1;
	    } else {
	    	factorObject[item] = 1;
	    }
	}
	return factorObject;	
}

var getSmallestMultiple = function getSmallestMultiple(N) {
	var factorArray = [];
	for(var i=2;i<=N;i++){
		var iFactorArray = arrayCount(getPrimeFactorArray(i));
		for(var j = 0; j < iFactorArray.length; j++) {
			if(iFactorArray[j] !== undefined) {
				if(factorArray.indexOf(j) === -1) {
					factorArray[j] = 1;
				} else {
					if(factorArray[j] < iFactorArray[j]) {
						factorArray[j] = iFactorArray[j];
					}
				}
			}
		}
	}
	return factorArray;
}

console.log(getSmallestMultiple(10));