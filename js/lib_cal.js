var sumOf1toN = function sumOf1toN(N) {
	return N * (N + 1) / 2;
}

var sumOf1squareToNsquare = function sumOf1squareToNsquare(N) {
	return (2 * N + 1) * (N + 1) * N / 6;
}

var sumOfLargeNumbers = function sumOfLargeNumbers(inputArray) {
    var resultArray = [];
    var maxLength = 0;
    inputArray.forEach(function(elem, index, array){
        if(elem.length > maxLength) {
            maxLength = elem.length;
        }
    });
    var carryIn = 0;
    for(var i=0; i< maxLength; i++) {
        var sumOfIthDigital = 0;
        inputArray.forEach(function(elem,index,array){
            var elemLength = elem.length;
            if(i < elemLength){
                sumOfIthDigital += parseInt(elem.substring(elemLength-i-1, elemLength-i));
            }
        });
        sumOfIthDigital += carryIn;
        resultArray.unshift(sumOfIthDigital%10);
        carryIn = parseInt(sumOfIthDigital/10);
    }
    while(sumOfIthDigital !== 0){
        resultArray.unshift(sumOfIthDigital%10);
        sumOfIthDigital = parseInt(sumOfIthDigital/10);
    }
    return resultArray.join("");
}

