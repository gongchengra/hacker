#include <stdio.h>
#include <stdlib.h>
long double factorial(int i) {
    if (i <= 1) {
        return 1;
    }
    return i * factorial(i - 1);
}
int main(int argc, char *argv[]) {
    int i;
    if (argc > 1) {
        i = atoi(argv[1]); // max value for ull.
    } else {
        printf("Input an integer less than 26:\n");
        scanf("%d", &i);
    }
    if(i < 0 || i > 25){
        printf("You input %d is invalid.\n", i);
        return 1;
    }
    printf("Factorial of %d is %Lf\n", i, factorial(i));
    return 0;
}
