#include <stdio.h>
int main() {
    int i, a[] = {1, 2, 3, 4, 5};
    char ch[] = "good!";
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("%s", ch);
    printf("\n");
    return 0;
}
