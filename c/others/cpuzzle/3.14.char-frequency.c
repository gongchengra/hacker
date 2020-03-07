#include <stdio.h>
int main() {
    int i, j, nw, nd[10];
    char s[100], c;
    j = 0;
    nw = 0;
    for (i = 0; i < 10; i++)
        nd[i] = 0;
    while ((c = getchar()) != '\n') {
        s[j] = c;
        switch (s[j]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            nd[s[j] - '0']++;
            break;
        default:
            nw++;
            break;
        }
        j++;
    }
    for (i = 0; i < 10; i++)
        printf("%d ", i);
    printf("\n");
    for (i = 0; i < 10; i++)
        printf("%d ", nd[i]);
    printf("\nnw=%d\n", nw);
}
