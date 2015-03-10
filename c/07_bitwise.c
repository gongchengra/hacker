#include <stdio.h>

int printBinary(int n){
    char byte[8*sizeof(int)]={0};
    int i=0;
    while (n && i < 8*sizeof(int)) {
        if (n & 1){
            byte[i] = 1;
            i++;
        } else{
            byte[i] = 0;
            i++;
        }
        n >>= 1;
    }
    for(i=8*sizeof(int)-1;i>=0;i--){
        printf("%d",byte[i]);
    }
    printf("\n");
}

int main()
{

    unsigned int a = 60; /* 60 = 0011 1100 */
    unsigned int b = 13; /* 13 = 0000 1101 */
    unsigned int c = 0;

    printf("A is %d ", a);
    printBinary(a);

    printf("B is %d ", b);
    printBinary(b);

    c = a & b;       /* 12 = 0000 1100 */
    printf("A & B is %d ", c);
    printBinary(c);

    c = a | b;       /* 61 = 0011 1101 */
    printf("A | B is %d ", c);
    printBinary(c);

    c = a ^ b;       /* 49 = 0011 0001 */
    printf("A ^ B is %d ", c);
    printBinary(c);

    c = ~a;          /*-61 = 1100 0011 */
    printf("~A is %d ", c);
    printBinary(c);

    c = a << 8;     /* 240 = 1111 0000 */
    printf("A<<8 is %d ", c);
    printBinary(c);

    c = a >> 2;     /* 15 = 0000 1111 */
    printf("A>>2 is %d ", c);
    printBinary(c);

}
