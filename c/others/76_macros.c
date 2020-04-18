/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 76_macros.c
* Author : gongchengra@gmail.com
* Purpose : https://pmihaylov.com/macros-in-c/
* Creation Date : 2020-04-16
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#if 1
#define bar()                                                                  \
    int var = 10;                                                              \
    printf("var in bar: %d\n", var)
#endif
#if 0
void bar() {
    int var = 10;
    printf("var in bar: %d\n", var);
}
void foo() {
    int var = 5; // error the variable defined in the macro will be in the same
                 // function as the other variable
    printf("var in foo: %d\n", var);
    bar();
}
#endif
#define printErrord(errorCode) printError(errorCode, "No message")
void printError(int errorCode, char *msg) {
    printf("Error code: %d (%s)\n", errorCode, msg);
}
// gcc -DDEBUG to make it work. or simply #define DEBUG
/*#define DEBUG*/
/*#undef DEBUG*/
#ifdef DEBUG
#define log_info(M, ...)                                                       \
    fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_info(M, ...)
#endif
#define MULTIPLY(x) ((x)*5) // instead of #define MULTIPLY(x) (x * 5)
#define MODIFY(arr, index)                                                     \
    do {                                                                       \
        arr[index] *= 5;                                                       \
        index++;                                                               \
    } while (0)
int main(int argc, char **argv) {
    bar();
    printError(9, "Bad alloc");
    printErrord(8);
    log_info("Start of program");
    int log = 10;
    log_info("my variable is %d", log);
    log_info("End of program");
    printf("%d\n", MULTIPLY(100));
    int arr[5] = {1, 2, 3, 4, 5}, i = 0;
    while (i < 5) {
        MODIFY(arr, i);
    }
    for (i = 0; i < 5; ++i) {
        printf("ELEMENT %d: %d\n", i, arr[i]);
    }
}
