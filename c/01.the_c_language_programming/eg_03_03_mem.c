/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_03_03_mem.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-14
* Last Modified : 2020-04-18 21:01:11+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binsearch(int x, int v[], int n) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (x > v[mid]) {
            lo = mid + 1;
        } else if (x == v[mid]) {
            return mid;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

#define size 10
int main(int argc, char **argv) {
    int a[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % size + i * size;
        printf("%4d", a[i]);
    }
    printf("\n");
    while (1) {
        int needle = (rand() % size) * (rand() % size);
        int location = binsearch(needle, a, size);
        if (location == -1) {
            printf("%d is not in the array.\n", needle);
        } else {
            printf("The location of %d is %d \n", needle, location);
            break;
        }
    }
}
