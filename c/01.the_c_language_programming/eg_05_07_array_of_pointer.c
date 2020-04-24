/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : t.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-19
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5
#define MAX 20
int main(int argc, char **argv) {
    int *arr[size], len[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % MAX + 1;
        len [i] = j;
        if ((arr[i] = malloc(j * sizeof(int))) != NULL) {
            for (int k = 0; k < j; k++) {
                *(arr[i] + k) = rand() % MAX;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        int max = *(arr[i]);
        int min = *(arr[i]);
        int sum = 0;
        printf("Row %d:", i);
        for(int j = 0; j < len[i]; j++) {
            printf("%4d", *(arr[i]+j));
            max = (*(arr[i]+j) > max) ? (*(arr[i]+j)) : max;
            min = (*(arr[i]+j) < min) ? (*(arr[i]+j)) : min;
            sum += *(arr[i]+j);
        }
        printf("\n");
        printf("The max value in row %d is %d\n", i, max);
        printf("The min value in row %d is %d\n", i, min);
        printf("The sum of values in row %d is %d\n", i, sum);
        printf("The average value in row %d is %4.1f\n", i, 1.0*sum/len[i]);
        printf("\n");
    }
    return 0;
}
