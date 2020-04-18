#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define newline printf("\n")
int main() {
    /*    int val[] = {1, 3, 5};*/
    /*    int *daytab[N]={&val[0], &val[1], &val[2]};*/
    /*    int *daytab[N]={val, val+1, val+2};*/
    int val[N];
    int *daytab[N];
    int(*pv)[N] = &val;
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        daytab[i] = val + i;
        *daytab[i] = rand() % (N * N * N);
        printf("%d\n", val[i]);
        // printf("%d\n", *daytab[i]);
        // printf("%d\n", (*pv)[i]);
        printf("%d\n", *((*pv) + i));
    }
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%lu\n", sizeof(a) / sizeof(a[0]));
    printf("%lu\n", sizeof(a[0]) / sizeof(a[0][0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        for (int j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++) {
            printf("%d ", a[i][j]);
        }
        newline;
    }
    int *b[2];
    int b1[N];
    printf("%lu\n", sizeof(b1) / sizeof(b1[0]));
    b[0] = b1;
    for (int i = 0; i < N; i++) {
        *(b[0] + i) = rand()/10000;
    }
    printf("%lu\n", sizeof(b) / sizeof(b[0]));
    printf("%lu\n",
            sizeof(*b[0]) / sizeof(int)); // 1 because *b[0] is pointer to int
    // https://stackoverflow.com/questions/492384/how-to-find-the-sizeof-a-pointer-pointing-to-an-array
    // according to this, there is no way to find out the size of the array that
    // b[0] or b[1] is pointing to
    for (int i = 0; i < sizeof(b1) / sizeof(b1[0]); i++) {
        printf("%d ", *(b[0] + i));
    }
    newline;
    int b2[] = {6};
    b[1] = b2;
    for (int i = 0; i < sizeof(b2) / sizeof(b2[0]); i++) {
        printf("%d ", *(b[1] + i));
    }
}
