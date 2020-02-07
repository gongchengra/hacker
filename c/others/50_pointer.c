#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int *s, i;
    /*    s = malloc(5 * sizeof(int));*/
    s = malloc(5 * sizeof(*s));
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        s[i] = i * rand() % 50;
    }
    int sum = 0;
    for (i = 0; i < 5; i++) {
        sum += s[i];
    }
    printf("%d", sum);
    return 0;
}
