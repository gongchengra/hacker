#include <stdio.h>
int main() {
    int i, a[5];
    char ch[5];
    for (i = 0; i < 5; i++)
        // wrong
        // scanf("%d", &a + i);
        // right 1
        // scanf("%d", &a[i]);
        // right 2
        scanf("%d", a + i);
    for (i = 0; i < 5; i++)
        // wrong
        // printf("%d ", *a + i);
        // right 1
        // printf("%d ", *(a + i));
        // right 2
        printf("%d ", a[i]);
    printf("\n");
    for (i = 0; i < 5; i++)
        // equals scanf("%c", ch[i]);
        scanf("%c", ch + i);
    ch[i] = '\0';
    printf("%s", ch);
    printf("\n");
    return 0;
}
