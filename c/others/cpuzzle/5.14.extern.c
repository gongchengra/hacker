#include <stdio.h>
int x = 155;
int main() {
    extern int y;
    printf("x=%d,y=%d\n", x, y);
    return 0;
}
int y = 5566;
