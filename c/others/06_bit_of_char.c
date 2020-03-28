/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 06_bit_of_char.c
* Author : gongchengra@gmail.com
* Purpose : http://codinghighway.com/?p=383
* Creation Date : 2014-11-13
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#define array_count(arr) (sizeof(arr) / sizeof(arr[0]))
int char_bits(void) {
    unsigned char c;
    int j;
    for (j = 0, c = ~0; c; j++, c >>= 1)
        ;
    return j;
}
char (*(*array_ptr)[12])(int);
int b(char, int, float);
char f(int);
char (*(*test_func(int (*t)(char, int, float), char **p))[12])(int);
int main(int argc, char *argv[]) {
    /*    char (*(*(*a)(int (*)(char, int, float), char **))[12])(int);*/
    char (*(*(*a)(int (*)(char, int, float), char **))[12])(int) = test_func;
    char (*arr[12])(int);
    int arrs[225] = {0};
    printf("%zu\n", sizeof(arrs) / sizeof(arrs[0]));
    printf("Array has %zu elements.\n", array_count(*(*a)(NULL, NULL)));
    array_ptr = &arr;
    arr[3] = f;
    printf("%zu %zu\n", sizeof(a),
           sizeof(char (*(*(*)(int (*)(char, int, float), char **))[12])(int)));
    printf("%zu %zu\n", sizeof((*a)(NULL, NULL)), sizeof(char (*(*)[12])(int)));
    printf("%zu\n", sizeof((*(*(*a)(NULL, NULL))[0])(0)));
    printf("char uses %d bits.\n", char_bits());
    printf("int uses %ld bits.\n", sizeof(int) * char_bits());
    printf("%zu %zu\n", sizeof(a),
           sizeof(char (*(*(*)(int (*)(char, int, float), char **))[12])(int)));
    printf("%zu %zu\n", sizeof((*a)(b, argv)), sizeof(char (*(*)[12])(int)));
    printf("%zu\n", sizeof((*(*(*a)(b, argv))[3])(9)));
    return 0;
}
char (*(*test_func(int (*t)(char, int, float), char **p))[12])(int) {
    return array_ptr;
}
char f(int x) { return 'a'; }
int b(char x, int y, float z) { return 0; }
