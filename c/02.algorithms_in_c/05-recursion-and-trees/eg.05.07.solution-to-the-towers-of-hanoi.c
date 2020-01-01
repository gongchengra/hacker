#include <stdio.h>
#include <stdlib.h>
void shift(int N, int d){
    printf("move %d to %s\n", N, ((d > 0) ? "right" : "left"));
}
void hanoi(int N, int d) {
    if (N == 0)
        return;
    hanoi(N - 1, -d);
    shift(N, d);
    hanoi(N - 1, -d);
}
int main(int argc, char *argv[]) {
    int i = (argc > 1) ? atoi(argv[1]) : 3;
    hanoi(i, 1);
}
