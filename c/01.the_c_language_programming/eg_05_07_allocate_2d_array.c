/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_05_07_allocate_2d_array.c
* Author : gongchengra@gmail.com
* Purpose : https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
* Creation Date : 2020-04-18
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
void fun1() {
    int r = 3, c = 4;
    int *arr = (int *)malloc(r * c * sizeof(int));
    int i, j, count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            *(arr + i * c + j) = ++count;
            printf("%d ", *(arr + i * c + j));
        }
}
void fun2() {
    int r = 3, c = 4, i, j, count;
    int *arr[r];
    for (i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count
            printf("%d ", arr[i][j]);
        }
}
void fun3() {
    int r = 3, c = 4, i, j, count;
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        arr[i] = (int *)malloc(c * sizeof(int));
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count
            printf("%d ", arr[i][j]);
        }
}
void fun4() {
    int r = 3, c = 4, len = 0;
    int *ptr, **arr;
    int count = 0, i, j;
    len = sizeof(int *) * r + sizeof(int) * c * r;
    arr = (int **)malloc(len);
    // ptr is now pointing to the first element in of 2D array
    ptr = (int *)(arr + r);
    // for loop to point rows pointer to appropriate location in 2D array
    for (i = 0; i < r; i++)
        arr[i] = (ptr + c * i);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count
            printf("%d ", arr[i][j]);
        }
}
void fun5() {
    int r = 3, c = 4, arr[r][c], count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = ++count;
            printf("%d ", arr[i][j]);
        }
    }
}
void fun6() {
    int r = 0, c = 0, *arr, count = 0;
    printf("input r:");
    scanf("%d", &r);
    printf("input c:");
    scanf("%d", &c);
    arr = malloc(r * c * sizeof(int));
    if (arr != NULL) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                *(arr + i * c + j) = ++count * (rand() % (100 + i * j));
                printf("%d ", *(arr + i * c + j));
            }
        }
    }
}
int main(int argc, char **argv) {
    fun1();
    printf("\n");
    fun2();
    printf("\n");
    fun3();
    printf("\n");
    fun4();
    printf("\n");
    fun5();
    printf("\n");
    fun6();
    printf("\n");
    return 0;
}
