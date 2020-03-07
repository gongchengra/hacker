#include <stdio.h>
int main() {
    int *p;
/*    *p = 65;*/
/*    printf("%d\n", *p);*/
    p = (int *)65;
    printf("%p\n", p);
    return 0;
}
