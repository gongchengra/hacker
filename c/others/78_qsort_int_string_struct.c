/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 78_qsort_int_string_struct.c
* Author : gongchengra@gmail.com
* Purpose :
http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml
* Creation Date : 2020-04-17
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* qsort int comparison function */
int int_cmp(const void *a, const void *b) {
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}
int icmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
/* integer array printing function */
void print_int_array(const int *array, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%d | ", array[i]);
    putchar('\n');
}
/* sorting integers using qsort() example */
void sort_integers_example() {
    int numbers[] = {7, 3, 4, 1, -1, 23, 12, 43, 2, -4, 5};
    size_t numbers_len = sizeof(numbers) / sizeof(int);
    puts("*** Integer sorting...");
    /* print original integer array */
    print_int_array(numbers, numbers_len);
    /* sort array using qsort functions */
    /*    qsort(numbers, numbers_len, sizeof(int), int_cmp);*/
    qsort(numbers, numbers_len, sizeof(int), icmp);
    /* print sorted integer array */
    print_int_array(numbers, numbers_len);
}
/* qsort C-string comparison function */
int cstring_cmp(const void *a, const void *b) {
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    /* strcmp functions works exactly as expected from
    comparison function */
}
int scmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
/* C-string array printing function */
void print_cstring_array(char **array, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%s | ", array[i]);
    putchar('\n');
}
/* sorting C-strings array using qsort() example */
void sort_cstrings_example() {
    char *strings[] = {"Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    size_t strings_len = sizeof(strings) / sizeof(char *);
    /** STRING */
    puts("*** String sorting...");
    /* print original string array */
    print_cstring_array(strings, strings_len);
    /* sort array using qsort functions */
    /*    qsort(strings, strings_len, sizeof(char *), cstring_cmp);*/
    qsort(strings, strings_len, sizeof(char *), scmp);
    /* print sorted string array */
    print_cstring_array(strings, strings_len);
}
/* an example of struct */
struct st_ex {
    char product[16];
    float price;
};
/* qsort struct comparision function (price float field) */
int struct_cmp_by_price(const void *a, const void *b) {
    struct st_ex *ia = (struct st_ex *)a;
    struct st_ex *ib = (struct st_ex *)b;
    return (int)(100.f * ia->price - 100.f * ib->price);
    /* float comparison: returns negative if b > a
    and positive if a > b. We multiplied result by 100.0
    to preserve decimal fraction */
}
/* qsort struct comparision function (product C-string field) */
int struct_cmp_by_product(const void *a, const void *b) {
    struct st_ex *ia = (struct st_ex *)a;
    struct st_ex *ib = (struct st_ex *)b;
    return strcmp(ia->product, ib->product);
    /* strcmp functions works exactly as expected from
    comparison function */
}
/* Example struct array printing function */
void print_struct_array(struct st_ex *array, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("[ product: %s \t price: $%.2f ]\n", array[i].product,
               array[i].price);
    puts("--");
}
/* sorting structs using qsort() example */
void sort_structs_example(void) {
    struct st_ex structs[] = {{"mp3 player", 299.0f}, {"plasma tv", 2200.0f},
                              {"notebook", 1300.0f},  {"smartphone", 499.99f},
                              {"dvd player", 150.0f}, {"matches", 0.2f}};
    size_t structs_len = sizeof(structs) / sizeof(struct st_ex);
    puts("*** Struct sorting (price)...");
    /* print original struct array */
    print_struct_array(structs, structs_len);
    /* sort array using qsort functions */
    qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_price);
    /* print sorted struct array */
    print_struct_array(structs, structs_len);
    puts("*** Struct sorting (product)...");
    /* resort using other comparision function */
    qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_product);
    /* print sorted struct array */
    print_struct_array(structs, structs_len);
}
/* MAIN program (calls all other examples) */
int main(int argc, char **argv) {
    /* run all example functions */
    sort_integers_example();
    sort_cstrings_example();
    sort_structs_example();
    return 0;
}
