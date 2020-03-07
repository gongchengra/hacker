#include <stdio.h>
#define s(a) sizeof(a)/sizeof(a[0])
int main() {
    int a[] = {1, 3, 5, 7, 9}, i;
    for (i = 0; i < s(a); ++i)
        printf("%d %d ", i[a], a[i]); // i[a]与a[i]等效
    printf("\n");
    for (i = 0; i < s(a); ++i)
        printf("%p ", &i[a]); // &i[a]与&a[i]等效
    printf("\n");
    for (i = 0; i < s(a); ++i)
        printf("%p ", &a[i]); // &a[i]与&i[a]等效
    printf("\n");
}
