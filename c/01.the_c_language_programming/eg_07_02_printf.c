#include <stdio.h>

int main () {

    int c;
    for( c = 'A' ; c <= 'z'; c++ ) {
        printf("ASCII value = %d, Character = %c\n", c , c );
    }

    char ch = 'A';
    char str[20] = "fresh2refresh.com";
    float flt = 10.234;
    double dbl = 20.123456;
    int no = 150;
    printf("Character is %c \n", ch);
    printf("String is %s \n" , str);
    printf("Float value is %f \n", flt);
    printf("Double value is %lf \n", dbl);
    printf("Integer value is %d\n" , no);
    printf("Octal value is %o \n", no);
    printf("Hexadecimal value is %x \n", no);
    return(0);
}
