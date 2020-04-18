/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_05_07_pointer_to_array_of_N_integers.c
* Author : gongchengra@gmail.com
* Purpose : https://www.geeksforgeeks.org/pointer-array-array-pointer/
* Creation Date : 2020-04-18
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p;
    p = arr; // p=arr[0]; p = &arr[0];
    printf("*p = %d\n", *p);
    int(*ptr)[5]; // Pointer to an array of 5 integers
    ptr = &arr;
    printf("*ptr = %p\n", *ptr);
    printf("**ptr = %d\n", **ptr);
    for (int i = 1; i < 5; i++) {
        printf("*(*ptr+i) = %d\n", *(*ptr + i));
    }
    int arr2d[5][5];
    ptr = arr2d;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            *(*(ptr + i) + j) = rand() % 1000;
            /*            printf("%4d", *(*(ptr + i) + j));*/
            printf("%4d", arr2d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
