var getPrimeNumbersLessthanN = function(N) {
	var primeArray = new Int8Array(N);
	for (var i=0; i<primeArray.length; i++) {
	  primeArray[i] = 0;
	}
	for(var i=0;i<=Math.sqrt(N);i++) {
		if(primeArray[i] === 0) {
			for(var j=i+2;j<primeArray.length;j++){
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

var calculateNthPrimeNumber = function(N) {
    var intN = parseInt(N);
    var maxNumber = Math.ceil(intN*Math.log(intN));
    console.log(maxNumber);
    console.log(getPrimeNumbersLessthanN(maxNumber).length);
} 

var getFirstNPrimeNumbers = function(N) {
	var resultArray = [];
    var intN = parseInt(N);
    if(intN < 1) {
        resultArray[0] = 'Invalid argument.';
    } else if (intN == 1) {
        resultArray[0] = '2';
    } else {
        //According to Prime_number_theorem,
        //the N prime number is approximately N*ln(N),
        //in order to make sure we can get N numbers, we multiply by a factor 1.2
        if(intN < 20) {
            var maxNumber = Math.ceil(3*intN*Math.log(intN));
        } else {
            var maxNumber = Math.ceil(1.2*intN*Math.log(intN));
        }
        var primeArray = new Int8Array(maxNumber);
        for (var i=0; i<primeArray.length; i++) {
            primeArray[i] = 0;
        }
        var sqrtMax = Math.sqrt(maxNumber);
        for(var i=0;i<=sqrtMax;i++) {
            if(primeArray[i] === 0) {
                for(var j=i+2;j<maxNumber;j++){
                    if((j+2)%(i+2) === 0) {
                        primeArray[j] = 1;
                    }
                }
            }
        }
        for(var i=0;i<primeArray.length,resultArray.length<intN;i++) {
            if(primeArray[i] === 0) {
                resultArray.push(i+2);
            }
        }
    }
	return resultArray;
}

var timer = function(func, args) {
	var startTime = new Date();
	var results = func(args);
	var endTime = new Date();
	console.log('Time used: ' + (endTime.getTime()-startTime.getTime()) + ' milliseconds');
	return results;
}

timer(getFirstNPrimeNumbers, 10000);  
