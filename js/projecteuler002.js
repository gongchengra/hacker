var fibArrayLessThanN = function fibArrayLessThanN(N) {
    var i = 0;
    var fib_array = [];
    fib_array[0] = 1;
    fib_array[1] = 2;
    for(i=0;fib_array[i]<N;i++){
        if(fib_array[i+1] > N) {
            return fib_array;
        }
        fib_array[i+2] = fib_array[i] + fib_array[i+1];
    }
}

var sumOfEvenValueInArray = function sumOfEvenValueInArray(ori_array) {
    var sum = 0;
    while (item = ori_array.shift()) {
        if(item%2 == 0) {
            sum += item;
        }
    }
    return sum; 
}

console.log(sumOfEvenValueInArray(fibArrayLessThanN(4000000))); //4613732

