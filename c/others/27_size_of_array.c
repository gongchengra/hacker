#include <stdio.h>
int main(int argc, char *argv[]) {
    int a[3] = {1, 2, 3};
    /*    int p= *(a+2);*/
    int i;
    int size = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < size; i++) {
        printf("%d\n", *(a + i));
    }
    // https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        int size = *(&arr + 1) - arr;
        printf("%d\n", size);
    }
    /*    &arr ==> Pointer to an array of 6 elements.*/
    /*    (&arr + 1) ==> Address of 6 integers ahead as*/
    /*    pointer type is pointer to array*/
    /*    of 6 integers.*/
    /*    *(&arr + 1) ==> Same address as (&arr + 1), but */
    /*    type of pointer is "int *".*/
    /*    *(&arr + 1) - arr ==> Since *(&arr + 1) points */
    /*    to the address 6 integers*/
    /*    ahead of arr, the difference*/
    /*    between two is 6.      */
}
