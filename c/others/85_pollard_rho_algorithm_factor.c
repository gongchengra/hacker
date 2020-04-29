/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 84_pollard_rho_algorithm_factor.c
* Author : gongchengra@gmail.com
* Purpose : https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
* Purpose :
https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
* Note: one_factor can not guarantee to find the factors, for example, 962061929
* Creation Date : 2020-04-29
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
long one_factor(long number) {
    long loop = 1, count, x_fixed = 2, x = 2, size = 2, factor;
    do {
        /*        printf("---- loop %4i ----\n", loop);*/
        count = size;
        do {
            x = (x * x + 1) % number;
            factor = gcd(labs(x - x_fixed), number);
            /*            printf("count = %4i, x= %6i, factor = %li\n", size -
             * count + 1, x, factor);*/
        } while (--count && (factor == 1));
        size *= 2;
        x_fixed = x;
        loop += 1;
    } while (factor == 1);
    return factor == number ? -1 : factor;
}
void all_factors(long number) {
    long res = one_factor(number);
    if (res == -1) {
        printf("Factor of %li not found.\n", number);
    } else {
        printf("Factors of %li:", number);
        do {
            printf(" %li", res);
            number = number / res;
            res = one_factor(number);
        } while (res != -1);
        printf(" %li\n", number);
    }
}
// Revised from
// https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
// May loop infinitely
#if 0
long PollardRho(long n) {
    if (n == 1) {
        return n;
    }
    if (n % 2 == 0) {
        return 2;
    }
    long x = (rand() % (n - 2)) + 2;
    long y = x;
    long c = (rand() % (n - 1)) + 1;
    long d = 1;
    while (d == 1) {
        x = (x * x + c) % n;
        y = (x * x + c) % n;
        printf("x=%d, y=%d\n", x, y);
        d = gcd(abs(x - y), n);
        if (d == n){
            return -1;
        }
    }
    return d;
}
#endif
long PollardRho(long n) {
    if (n == 1) {
        return n;
    }
    if (n % 2 == 0) {
        return 2;
    }
    long x = 3, y = 5, d, count, size = 2;
    do {
        count = size;
        do {
            x = (x * x + 1) % n;
            d = gcd(labs(x - y), n);
        } while (--count && (d == 1));
        size *= 2;
        y = x;
    } while (d == 1);
    return d == n ? -1 : d;
}
void Pollard(long n) {
    long res = PollardRho(n);
    if (res == -1) {
        printf("Factor of %li not found.\n", n);
    } else {
        printf("Factors of %li:", n);
        do {
            printf(" %li", res);
            n = n / res;
            res = PollardRho(n);
        } while (res != -1);
        printf(" %li\n", n);
    }
}
int main(int argc, char **argv) {
    srand(time(NULL));
    long number = (argc == 2) ? atoi(argv[1]) : rand();
/*    printf("%ld\n", number);*/
    all_factors(number);
/*    printf("\n");*/
    /*        printf("%d", PollardRho(number));*/
    Pollard(number);
    return 0;
}
