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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int one_factor(int number) {
    int loop = 1, count, x_fixed = 2, x = 2, size = 2, factor;
    do {
        /*        printf("---- loop %4i ----\n", loop);*/
        count = size;
        do {
            x = (x * x + 1) % number;
            factor = gcd(abs(x - x_fixed), number);
            /*            printf("count = %4i, x= %6i, factor = %i\n", size -
             * count + 1, x, factor);*/
        } while (--count && (factor == 1));
        size *= 2;
        x_fixed = x;
        loop += 1;
    } while (factor == 1);
    return factor == number ? -1 : factor;
}
void all_factors(int number) {
    int res = one_factor(number);
    if (res == -1) {
        printf("Factor of %i not found.\n", number);
    } else {
        printf("Factors of %i:", number);
        do {
            printf(" %i", res);
            number = number / res;
            res = one_factor(number);
        } while (res != -1);
        printf(" %i\n", number);
    }
}
// Revised from
// https://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
// May loop infinitely
#if 0
int PollardRho(int n) {
    if (n == 1) {
        return n;
    }
    if (n % 2 == 0) {
        return 2;
    }
    int x = (rand() % (n - 2)) + 2;
    int y = x;
    int c = (rand() % (n - 1)) + 1;
    int d = 1;
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
int PollardRho(int n) {
    if (n == 1) {
        return n;
    }
    if (n % 2 == 0) {
        return 2;
    }
    int x = 3, y = 5, d, count, size = 2;
    do {
        count = size;
        do {
            x = (x * x + 1) % n;
            d = gcd(abs(x - y), n);
        } while (--count && (d == 1));
        size *= 2;
        y = x;
    } while (d == 1);
    return d == n ? -1 : d;
}
void Pollard(int n) {
    int res = PollardRho(n);
    if (res == -1) {
        printf("Factor of %i not found.\n", n);
    } else {
        printf("Factors of %i:", n);
        do {
            printf(" %i", res);
            n = n / res;
            res = PollardRho(n);
        } while (res != -1);
        printf(" %i\n", n);
    }
}
int main(int argc, char **argv) {
    srand(time(NULL));
    int number = (argc == 2) ? atoi(argv[1]) : rand();
    printf("%d\n", number);
    all_factors(number);
    printf("\n");
    /*        printf("%d", PollardRho(number));*/
    Pollard(number);
    return 0;
}
