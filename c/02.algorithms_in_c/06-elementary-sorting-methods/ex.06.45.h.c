#include <math.h>
#include <stdio.h>
int main() {
    int i, j, k;
    float f[10], s[10], a[20];
    for (i = 0; i < 10; i++) {
        f[i] = 9 * pow(4, i) - 9 * pow(2, i) + 1;
        s[i] = pow(4, i) - 3 * pow(2, i) + 1;
        printf("%d %f %f\n", i, f[i], s[i]);
    }
    /*
    i = j = k = 0;
    while (i < 10 && j < 10) {
        if (f[i] > s[j]) {
            a[k++] = s[j++];
        } else {
            a[k++] = f[i++];
        }
    }
    while (i < 10) {
        a[k++] = f[i++];
    }
    while (j < 10) {
        a[k++] = s[j++];
    }
    */
    for (i = j = k = 0; k < 20; k++) {
        if (i == 10) {
            a[k] = s[j++];
            continue;
        }
        if (j == 10) {
            a[k] = f[i++];
            continue;
        }
        a[k] = (f[i] < s[j]) ? f[i++] : s[j++];
    }
    for (k = 0; k < 20; k++)
        if (a[k] > 0)
            printf("%f ", a[k]);
}
