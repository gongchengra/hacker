fib = function fib(num) {
    if (num > 2) {
        return fib(num - 2) + fib(num - 1);
    } else {
        return 1;
    }
};

fib_iter = function fib_iter(num) {
    if (num < 2) {
        return num;
    } else {
        var i = 1;
        var sum = 0;
        while (i <= num) {
            f1 = fib_iter(i - 2);
            f2 = fib_iter(i - 1);
            sum = f1 + f2;
            f1 = f2;
            f2 = sum;
            i++;
        }
        return sum;
    }
};

