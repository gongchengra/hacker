#include <stdio.h>
int main() {
    int sum = 1, i = 0;
    for (i = 2; i <= 5; i++)
        sum = i * sum;
    printf("5!=%d\n", sum);
}
