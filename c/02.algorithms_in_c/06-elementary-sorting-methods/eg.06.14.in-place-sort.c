#include <stdio.h>
void insitu(char data[], int a[], int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        char v = data[i];
        for (k = i; a[k] != i; k = a[j], a[j] = j) {
            j = k;
            data[k] = data[a[k]];
        }
        data[k] = v;
        a[k] = k;
    }
}
int main() {
    char data[] = {'a', 's', 'o', 'r', 't', 'i', 'n', 'g',
                   'e', 'x', 'a', 'm', 'p', 'l', 'e'};
    int a[] = {0, 10, 8, 14, 7, 5, 13, 11, 6, 2, 12, 3, 1, 4, 9};
    for (int i = 0; i < sizeof(data); i++) {
        printf("%c ", data[i]);
    }
    insitu(data, a, sizeof(data));
    printf("\n");
    for (int i = 0; i < sizeof(data); i++) {
        printf("%c ", data[i]);
    }
    return 0;
}
