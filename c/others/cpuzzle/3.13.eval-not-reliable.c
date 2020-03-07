#include <stdio.h>
int main() {
    int i = 0, n = 5;
    int y[5], x[] = {1, 2, 3, 4, 5};
    while (i < n) {
        // warning: unsequenced modification and access to 'i' [-Wunsequenced]
        // y[i] = x[i++];
        // right way
        y[i] = x[i];
        i++;
    }
    // better way:
    // for (i = 0; i < n; i++) y[i] = x[i];
    for (i = 0; i < n; i++)
        printf("%d ", y[i]);
}
