/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 89_24_point_solver.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-09-29
* Last Modified : 2020-09-29 21:40:23+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>

void solve(int x, int y, int z, int w) {
    if (x + y + z + w == 24) {
        printf("%d + %d + %d + %d = 24\n", x, y, z, w);
    }
    if (x + y + z - w == 24) {
        printf("%d + %d + %d + %d = 24\n", x, y, z, w);
    }
    if ((x + y) * (z + w) == 24) {
        printf("(%d + %d) * (%d + %d) == 24\n", x, y, z, w);
    }
    if ((x - y) * (z + w) == 24) {
        printf("(%d - %d) * (%d + %d) == 24\n", x, y, z, w);
    }
    if ((x - y) * (z - w) == 24) {
        printf("(%d - %d) * (%d - %d) == 24\n", x, y, z, w);
    }
    if ((x + y + z) * w == 24) {
        printf("(%d + %d + %d) * %d == 24\n", x, y, z, w);
    }
    if ((x - y - z) * w == 24) {
        printf("(%d - %d - %d) * %d == 24\n", x, y, z, w);
    }
    if ((x + y - z) * w == 24) {
        printf("(%d + %d - %d) * %d == 24\n", x, y, z, w);
    }
    if ((x * y * z) / w == 24) {
        printf("(%d * %d * %d) / %d == 24\n", x, y, z, w);
    }
    if ((x * y) * (z + w) == 24) {
        printf("(%d * %d) * (%d + %d) == 24\n", x, y, z, w);
    }
    if ((x * y) * (z - w) == 24) {
        printf("(%d * %d) * (%d - %d) == 24\n", x, y, z, w);
    }
    if ((x * y) * z - w == 24) {
        printf("(%d * %d) * %d - %d == 24\n", x, y, z, w);
    }
    if ((x * y) * z + w == 24) {
        printf("(%d * %d) * %d + %d == 24\n", x, y, z, w);
    }
    if (x * y * z * w == 24) {
        printf("%d * %d * %d * %d == 24\n", x, y, z, w);
    }
    if ((x + y) + (z / w) == 24) {
        printf("(%d + %d) + (%d / %d) == 24\n", x, y, z, w);
    }
    if ((x + y) * (z / w) == 24) {
        printf("(%d + %d) * (%d / %d) == 24\n", x, y, z, w);
    }
    if ((x * y) + z + w == 24) {
        printf("(%d * %d) + %d + %d == 24\n", x, y, z, w);
    }
    if ((x * y) + z - w == 24) {
        printf("(%d * %d) + %d - %d == 24\n", x, y, z, w);
    }
    if ((x * y) - (z / w) == 24) {
        printf("(%d * %d) - (%d / %d) == 24\n", x, y, z, w);
    }
    if ((x * y) + (z / w) == 24) {
        printf("(%d * %d) + (%d / %d) == 24\n", x, y, z, w);
    }
    if ((x * y) - z - w == 24) {
        printf("(%d * %d) - %d - %d == 24\n", x, y, z, w);
    }
    if ((x * y) + (z * w) == 24) {
        printf("(%d * %d) + (%d * %d) == 24\n", x, y, z, w);
    }
    if ((x * y) - (z * w) == 24) {
        printf("(%d * %d) - (%d * %d) == 24\n", x, y, z, w);
    }
    if ((x * y) / (z * w) == 24) {
        printf("(%d * %d) / (%d * %d) == 24\n", x, y, z, w);
    }
    if ((z != w) && ((x * y) / (z - w) == 24)) {
        printf("(%d * %d) / (%d - %d) == 24\n", x, y, z, w);
    }
    if ((x * y) / (z + w) == 24) {
        printf("(%d * %d) / (%d + %d) == 24\n", x, y, z, w);
    }
}

int main(int argc, char **argv) {
    if (argc == 5) {
        int i = strtol(argv[1], NULL, 10);
        int j = strtol(argv[2], NULL, 10);
        int k = strtol(argv[3], NULL, 10);
        int l = strtol(argv[4], NULL, 10);
        solve(i, j, k, l);
        solve(i, j, l, k);
        solve(i, k, l, j);
        solve(i, k, j, l);
        solve(i, l, j, k);
        solve(i, l, k, j);
        solve(j, i, k, l);
        solve(j, i, l, k);
        solve(j, k, i, l);
        solve(j, k, l, i);
        solve(j, l, k, i);
        solve(j, l, i, k);
        solve(k, i, j, l);
        solve(k, i, l, j);
        solve(k, j, l, i);
        solve(k, j, i, l);
        solve(k, l, i, j);
        solve(k, l, j, i);
        solve(l, i, j, k);
        solve(l, i, k, j);
        solve(l, j, k, i);
        solve(l, j, i, k);
        solve(l, k, i, j);
        solve(l, k, j, i);
    } else {
        printf("Please input four integers.\n");
    }
    return 0;
}
