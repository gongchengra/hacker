#include <stdio.h>
#include <string.h>
#define N 10000
int main(int argc, char *argv[]) {
    int i, j, t;
    char a[N], *p = argv[1];
    for (i = 0; i < N - 1; a[i] = t, i++)
        if ((t = getchar()) == EOF)
            break;
    a[i] = '\0';
    printf("%s\n", a);
    int s = strlen(a);
    for (i = 0; i < s; i++)
        if (strncmp(&a[i], p, strlen(p)) == 0)
            printf("%d ", i);
    printf("\n");
    return 0;
}
