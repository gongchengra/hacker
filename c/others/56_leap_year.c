#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s to tell whether %s is leap year.\n", argv[0],
               argv[0]);
    } else {
        int year = atoi(argv[1]);
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d is leap year\n", year);
        } else {
            printf("%d is not leap year\n", year);
        }
    }
    return 0;
}
