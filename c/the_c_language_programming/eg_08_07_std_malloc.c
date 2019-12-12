#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *str;
    str = (char *)malloc(1);
    strcpy(str, "laogongshuo");
    printf("String = %s,  Address = %u\n", str, (int)&str);
    str = (char *)realloc(str, 1);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, (int)&str);
    free(str);

    int n = 1024, sum = 0, *ptr;
    // https://stackoverflow.com/questions/41822904/why-does-malloc1-work-for-storing-4-byte-integers
    // undefined behavior to use more memory than allocated;
    // ptr = (int *) malloc(1);
    ptr = (int *)malloc(n * sizeof(ptr));
    for (int i = 0; i < n; i++) {
        // ptr[i] = (i+1)*(i+1)*(i+1);
        ptr[i] = i + 1;
        sum += ptr[i];
        // printf("%d, ", ptr[i]);
    }
    printf("%d\n", sum);
    free(ptr);

    int *p;
    printf("Pointer before malloc(): %p\n", p);
    p = (int *)malloc(sizeof(int));
    printf("Pointer after malloc(): %p\n", p);
    p[0] = 100;
    free(p);

    return (0);
}
