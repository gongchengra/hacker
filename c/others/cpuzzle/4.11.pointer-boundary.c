#include <stdio.h>
int main() {
    int a[] = {1, 3, 5, 7, 9};
    int *p;
    for (p = a; p < a + 5; ++p)
        printf("%d ", *p);
    printf("\n");
    // wrong for(p; p >= a; --p)
    for (--p; p >= a; --p)
        printf("%d ", *p);
    printf("\n");
    return 0;
}
