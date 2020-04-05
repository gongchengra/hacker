#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int *s, i, sum = 0;
    /*    s = malloc(5 * sizeof(int));*/
    s = malloc(5 * sizeof(*s));
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        s[i] = i * (rand() % 50);
        sum += s[i];
        printf("%4d", s[i]);
    }
    printf("\nsum = %d", sum);
    return 0;
}
