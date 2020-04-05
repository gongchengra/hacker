#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
// generate N distinct numbers from 0 to N in random order
void randN() {
    int i, r[N], c = 0, j;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        r[i] = -1;
    }
    for (i = 0; c < N;) {
        j = rand() % 10;
        for (; j < N;) {
            if (r[j] == -1) {
                r[j] = i++;
                c++;
                break;
            } else {
                j++;
            }
        }
    }
    for (i = 0; i < N; i++)
        printf("%d ", r[i]);
}
void fisherYates() {
    int i, r[N], k, t;
    for (i = 0; i < N; i++) {
        r[i] = i;
    }
    srand(time(NULL));
    for (i = N - 1; i >= 0; i--) {
        k = rand() % 10;
        t = r[k];
        r[k] = r[i];
        r[i] = t;
    }
    for (i = 0; i < N; i++)
        printf("%d ", r[i]);
}
int main() {
    randN();
    printf("\n");
    fisherYates();
}
