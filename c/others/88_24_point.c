/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 88_24_point.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-09-29
* Last Modified : 2020-09-29 21:46:24+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>

int combine(float x, float y, float z, float w) {
    if (x + y + z + w == 24) {
        return 1;
    } else if (x + y + z - w == 24) {
        return 1;
    } else if ((x + y) * (z + w) == 24) {
        return 1;
    } else if ((x - y) * (z + w) == 24) {
        return 1;
    } else if ((x - y) * (z - w) == 24) {
        return 1;
    } else if ((x + y + z) * w == 24) {
        return 1;
    } else if ((x - y - z) * w == 24) {
        return 1;
    } else if ((x + y - z) * w == 24) {
        return 1;
    } else if ((x * y * z) / w == 24) {
        return 1;
    } else if ((x * y) * (z + w) == 24) {
        return 1;
    } else if ((x * y) * (z - w) == 24) {
        return 1;
    } else if ((x * y) * z - w == 24) {
        return 1;
    } else if ((x * y) * z + w == 24) {
        return 1;
    } else if (x * y * z * w == 24) {
        return 1;
    } else if ((x + y) + (z / w) == 24) {
        return 1;
    } else if ((x + y) * (z / w) == 24) {
        return 1;
    } else if ((x * y) + z + w == 24) {
        return 1;
    } else if ((x * y) + z - w == 24) {
        return 1;
    } else if ((x * y) - (z / w) == 24) {
        return 1;
    } else if ((x * y) + (z / w) == 24) {
        return 1;
    } else if ((x * y) - z - w == 24) {
        return 1;
    } else if ((x * y) + (z * w) == 24) {
        return 1;
    } else if ((x * y) - (z * w) == 24) {
        return 1;
    } else if ((x * y) / (z * w) == 24) {
        return 1;
    } else if ((x * y) / (z - w) == 24) {
        return 1;
    } else if ((x * y) / (z + w) == 24) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    int i, j, k, l;
    for (i = 1; i < 14; i++) {
        for (j = i; j < 14; j++) {
            for (k = j; k < 14; k++) {
                for (l = k; l < 14; l++) {
                    if (combine(i, j, k, l) == 1 || combine(i, j, l, k) == 1 ||
                        combine(i, k, l, j) == 1 || combine(i, k, j, l) == 1 ||
                        combine(i, l, j, k) == 1 || combine(i, l, k, j) == 1 ||
                        combine(j, i, k, l) == 1 || combine(j, i, l, k) == 1 ||
                        combine(j, k, i, l) == 1 || combine(j, k, l, i) == 1 ||
                        combine(j, l, k, i) == 1 || combine(j, l, i, k) == 1 ||
                        combine(k, i, j, l) == 1 || combine(k, i, l, j) == 1 ||
                        combine(k, j, l, i) == 1 || combine(k, j, i, l) == 1 ||
                        combine(k, l, i, j) == 1 || combine(k, l, j, i) == 1 ||
                        combine(l, i, j, k) == 1 || combine(l, i, k, j) == 1 ||
                        combine(l, j, k, i) == 1 || combine(l, j, i, k) == 1 ||
                        combine(l, k, i, j) == 1 || combine(l, k, j, i) == 1) {
                        printf("%d %d %d %d\n", i, j, k, l);
                    }
                }
            }
        }
    }
}

float equal24(float x, float y) {
    if ((x + y == 24) || (x * y == 24) || (x - y == 24) || (y - x == 24) ||
        (y != 0 && x / y == 24) || (x != 0 && y / x == 24)) {
        return 1;
    }
    return 0;
}
