var quicksort = function quicksort(inputArray) {
    var sortedArray = inputArray;
    if (sortedArray.length <= 1) {
        return sortedArray;
    }
    var pivot = sortedArray[Math.floor(sortedArray.length / 2)];
    var lessArray = [];
    var greatArray = [];
    sortedArray.forEach(function(elem, index, arr) {
        if (index > 0) {
            if (elem > pivot) {
                greatArray.push(elem);
            } else {
                lessArray.push(elem);
            }

        }
    });
    return quicksort(lessArray).concat(pivot).concat(quicksort(greatArray));
}

var generateRandomNumberArray = function generateRandomNumberArray(N) {
    var randomArray = [];
    for (var i = 0; i < N; i++) {
        randomArray[i] = Math.floor(Math.random() * N + 1);
    }
    return randomArray;
};

console.log(quicksort(generateRandomNumberArray(1000)));

var swap = function swap(inputArray, left, right) {
    var tmp = inputArray[left];
    inputArray[left] = inputArray[right];
    inputArray[right] = tmp;
    return inputArray;
}

var quicksort_partition = function quicksort_partition(inputArray, left, right, pivotIndex) {
    var pivot = inputArray[pivotIndex];
    swap(inputArray, pivotIndex, right);
    var storeIndex = left;
    inputArray.forEach(function(elem, index, arr) {
        if (index >= left && index < right) {
            if (elem <= pivot) {
                swap(inputArray, index, storeIndex);
                storeIndex++;
            }
        }
    });
    swap(inputArray, storeIndex, right);
    return storeIndex;
};

var quicksort1 = function quicksort1(inputArray, left, right) {
    var quicksort_partition = function quicksort_partition(inputArray, left, right, pivotIndex) {
        var pivot = inputArray[pivotIndex];
        swap(inputArray, pivotIndex, right);
        var storeIndex = left;
        inputArray.forEach(function(elem, index, arr) {
            if (index >= left && index < right) {
                if (elem <= pivot) {
                    swap(inputArray, index, storeIndex);
                    storeIndex++;
                }
            }
        });
        swap(inputArray, storeIndex, right);
        return storeIndex;
    };
    var sortedArray = inputArray;
    if (sortedArray.length <= 1) {
        return sortedArray;
    }
    if (left < right) {
        var pivotIndex = Math.floor(sortedArray.length / 2);
        var pivotNewIndex = quicksort_partition(sortedArray, left, right, pivotIndex);
        quicksort1(sortedArray, left, pivotNewIndex - 1);
        quicksort1(sortedArray, pivotNewIndex + 1, right);
        return sortedArray;
    }
};
console.log(quicksort1(generateRandomNumberArray(10), 0, 9));

