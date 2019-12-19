#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// A normal function with an int parameter and void return type
void fun(int a) { printf("Value of a is %d\n", a); }

void add(int a, int b) { printf("Addition is %d\n", a + b); }
void subtract(int a, int b) { printf("Subtraction is %d\n", a - b); }
void multiply(int a, int b) { printf("Multiplication is %d\n", a * b); }

void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }
// A function that receives a simple function as parameter and calls the
// function
void wrapper(void (*fun)()) { fun(); }

// A compare function that is used for searching an integer
// array
bool scompare(const void *a, const void *b) { return (*(int *)a == *(int *)b); }
// General purpose search() function that can be used for searching an element
// *x in an array arr[] of arr_size. Note that void pointers are used so that
// the function can be called by passing a pointer of any type.  ele_size is
// size of an array element
int search(void *arr, int arr_size, int ele_size, void *x,
           bool scompare(const void *, const void *)) {
    // Since char takes one byte, we can use char pointer for any type/ To get
    // pointer arithmetic correct, we need to multiply index with size of an
    // array element ele_size
    char *ptr = (char *)arr;
    for (int i = 0; i < arr_size; i++)
        if (scompare(ptr + i * ele_size, x))
            return i;
    // If element not found
    return -1;
}

// A sample comparator function that is used for sorting an integer array in
// ascending order.  To sort any array for any other data type and/or criteria,
// all we need to do is write more compare functions.  And we can use the same
// qsort()
int qcompare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
    // fun_ptr is a pointer to function fun()
    void (*fun_ptr)(int) = &fun;
    /* The above line is equivalent of following two void (*fun_ptr)(int);
     * fun_ptr = &fun; */
    // Invoking fun() using fun_ptr
    (*fun_ptr)(10);

    // A function’s name can also be used to get functions’ address.
    //        void (*fun_ptr)(int) = fun;
    //       fun_ptr(10);

    // fun_ptr_arr is an array of function pointers
    //    void (*fun_ptr_arr[])(int, int) = {&add, &subtract, &multiply};
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;
    printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply\n");
    scanf("%d", &ch);
    if (ch > 2) {
        return 0;
    }
    //    (*fun_ptr_arr[ch])(a, b);
    fun_ptr_arr[ch](a, b);

    wrapper(fun1);
    wrapper(fun2);

    int arr[] = {2, 5, 9, 8, 7, 90, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Returned index is %d\n", search(arr, n, sizeof(int), &x, scompare));

    qsort(arr, n, sizeof(int), qcompare);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Returned index is %d\n", search(arr, n, sizeof(int), &x, scompare));

    return 0;
}
