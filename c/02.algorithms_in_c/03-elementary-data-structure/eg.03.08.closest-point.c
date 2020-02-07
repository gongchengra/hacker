#include "point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float randFloat() {
    srand(time(NULL));
    return 1.0 * rand() / RAND_MAX;
}
/*
 * This program illustrates the use of an array of structures, and is
 * representative of the typical situation where we save items in an array to
 * process them later, during some computation. It counts the number of
 * pairs of N randomly generated points in the unit square that can be
 * connected by a straight line of length less than d.
 */
int main(int argc, char *argv[]) {
    float d = atof(argv[2]);
    int i, j, cnt = 0, n = atoi(argv[1]);
    point *a = malloc(n * sizeof(*a));
    for (i = 0; i < n; i++) {
        a[i].x = randFloat();
        a[i].y = randFloat();
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (distance(a[i], a[j]) < d)
                cnt++;
    printf("%d edges shorter than %f\n", cnt, d);
    return 0;
}
