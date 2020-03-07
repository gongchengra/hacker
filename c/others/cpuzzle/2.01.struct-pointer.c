#include <stdio.h>
struct pencil {
    int hardness;
    char marker;
    int number;
};
int main() {
    struct pencil p[3]; // 第9行定义p[3]
    struct pencil *pen; // 第10行定义*pen
    p[0].hardness = 2;
    p[0].marker = 'F';
    p[0].number = 485;
    p[1].hardness = 0;
    p[1].marker = 'G';
    p[1].number = 38;
    p[2].hardness = 3;
    p[2].marker = 'E';
    p[2].number = 108;
    printf("Hardness Marker Number\n");
    for (pen = p; pen <= p + 2; ++pen)
/*        printf("%4d%8c%8d\n", (*pen).hardness, (*pen).marker, (*pen).number);*/
        printf("%4d%8c%8d\n", pen->hardness, pen->marker, pen->number);
}
