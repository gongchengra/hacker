/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
 * File Name : pi.c
 * Author : gongchengra@gmail.com
 * Purpose : Calculate pi
 *
 * pi=16actan(1/5)-4actan(1/239)
 *
 * actan（x）=x-x**3/3+x**5/5-x**7/7+....
 *
 * pi=3.2-4/239-1/3*(3.2/25-4/239**3)+1/5*(3.2/25**2-4/239**5)+...
 *
 * use d5 to store 16/5, 16/5**3, 16/5**5, ...
 *
 * use d239 to store 4/239, 4/239**3, 4/239**5, ...
 *
 * use t5 to store 16/5, 1/3*(16/5**3), 1/5*(16/5**5), ...
 *
 * use t239 to store 4/239, 1/3*(4/239**3), 1/5*(4/239**5), ...
 *
 * use pi to store the final result
 * Creation Date : 2015-01-07
 * Last Modified :
 _._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#define NUMBER 1000
int array_divide_number(int *array, int number, int size) {
    int i, tmp;
    int modulo = 0;
    for (i = 0; i < size; i++) {
        tmp = array[i] + modulo * 10;
        array[i] = tmp / number;
        modulo = tmp % number;
    }
    return 0;
}
void print_array(int *array, int size) {
    int i, last;
    for (last = size - 1; last >= 0; last--) {
        if (array[last] != 0) {
            break;
        }
    }
    for (i = 0; i <= last; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}
void copy_array(int *source, int *target, int size) {
    int i;
    for (i = 0; i < size; i++) {
        target[i] = source[i];
    }
}
void plus_array(int *augend, int *addend, int *sum, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        sum[i] = augend[i] + addend[i];
        if (sum[i] > 9) {
            sum[i] = sum[i] % 10;
            sum[i - 1]++;
        }
    }
}
void minus_array(int *minuend, int *subtracter, int *answer, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        if (minuend[i] >= subtracter[i] || i == 0) {
            answer[i] = minuend[i] - subtracter[i];
        } else {
            if (minuend[i - 1] == 0) {
                minuend[i - 2]--;
                minuend[i - 1] = 10;
            }
            minuend[i - 1]--;
            answer[i] = 10 + minuend[i] - subtracter[i];
        }
    }
}
int main() {
    int i;
    int flag = 1;
    int d5[NUMBER] = {0};
    int t5[NUMBER] = {0};
    int d239[NUMBER] = {0};
    int t239[NUMBER] = {0};
    int pi[NUMBER] = {0};
    d5[0] = 16;
    d239[0] = 4;
    array_divide_number(d5, 5, NUMBER);
    array_divide_number(d239, 239, NUMBER);
    // every iteration will increase three valid digitals
    for (i = 1; i < NUMBER * 3 / 2; i += 2) {
        copy_array(d5, t5, NUMBER);
        copy_array(d239, t239, NUMBER);
        array_divide_number(t5, i, NUMBER);
        array_divide_number(t239, i, NUMBER);
        if (flag > 0) {
            plus_array(pi, t5, pi, NUMBER);
            minus_array(pi, t239, pi, NUMBER);
        } else {
            minus_array(pi, t5, pi, NUMBER);
            plus_array(pi, t239, pi, NUMBER);
        }
        flag = -1 * flag;
        array_divide_number(d5, 5 * 5, NUMBER);
        array_divide_number(d239, 239 * 239, NUMBER);
    }
    print_array(pi, NUMBER);
    return 0;
}
