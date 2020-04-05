/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 16_pi_SF.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2015-01-12
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <string.h>
#define NUMBER 1000
void array_divide_number(short *array, const int number, const int size) {
    int i;
    int modulo = 0;
    for (i = 0; i < size; i += 5) {
        int tmp;
        tmp = array[i] + modulo * 10;
        array[i] = tmp / number;
        modulo = tmp % number;
        tmp = array[i + 1] + modulo * 10;
        array[i + 1] = tmp / number;
        modulo = tmp % number;
        tmp = array[i + 2] + modulo * 10;
        array[i + 2] = tmp / number;
        modulo = tmp % number;
        tmp = array[i + 3] + modulo * 10;
        array[i + 3] = tmp / number;
        modulo = tmp % number;
        tmp = array[i + 4] + modulo * 10;
        array[i + 4] = tmp / number;
        modulo = tmp % number;
    }
}
void print_array(short *array, int size) {
    int i, last;
    for (last = size - 1; last >= 0; --last) {
        if (array[last] != 0) {
            break;
        }
    }
    for (i = 0; i <= last; ++i) {
        printf("%d", array[i]);
    }
    printf("\n");
}
void plus_array(short *augend, short *addend, short *sum, const int size) {
    int i;
    for (i = size - 1; i >= 0; --i) {
        sum[i] = augend[i] + addend[i];
        if (sum[i] > 9) {
            sum[i] = sum[i] % 10;
            sum[i - 1]++;
        }
    }
}
void minus_array(short *minuend, short *subtracter, short *answer,
                 const int size) {
    int i;
    for (i = size - 1; i >= 0; --i) {
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
    short d5[NUMBER] = {0};
    short t5[NUMBER] = {0};
    short d239[NUMBER] = {0};
    short t239[NUMBER] = {0};
    short pi[NUMBER] = {0};
    d5[0] = 16;
    d239[0] = 4;
    array_divide_number(d5, 5, NUMBER);
    array_divide_number(d239, 239, NUMBER);
    // every iteration will increase three valid digitals
    const int end = NUMBER * 3 / 2;
    for (i = 1; i < end; i += 2) {
        memcpy(t5, d5, NUMBER * sizeof(short));
        memcpy(t239, d239, NUMBER * sizeof(short));
        array_divide_number(t5, i, NUMBER);
        array_divide_number(t239, i, NUMBER);
        if (flag == 1) {
            plus_array(pi, t5, pi, NUMBER);
            minus_array(pi, t239, pi, NUMBER);
        } else {
            minus_array(pi, t5, pi, NUMBER);
            plus_array(pi, t239, pi, NUMBER);
        }
        flag = -1 * flag;
        array_divide_number(d5, 25, NUMBER);
        array_divide_number(d239, 57121, NUMBER);
    }
    print_array(pi, NUMBER);
    return 0;
}
