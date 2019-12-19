#include <stdio.h>

void dumpMem(char *start, int size)
{
    int i=0;
    for(i=0; i<size; i++){
        printf("0x%x ", start[i]&0xff);
    }
    printf("\n");
}

int main()
{
    double d1=0.01;
    double d2=0.05;

    double ret=d1+d2;

    printf("0.01: ");
    dumpMem((char *)&d1, sizeof(double));
    printf("80 out: %.80f\n", d1);

    printf("0.05: ");
    dumpMem((char *)&d2, sizeof(double));
    printf("80 out: %.80f\n", d2);

    printf("result of 0.01+0.05: ");
    dumpMem((char *)&ret, sizeof(double));
    printf("80 out: %.80f\n", ret);
    printf("18 out: %.18f\n", ret);
    printf("19 out: %.19f\n", ret);
}
