#include <stdio.h>
int main() {
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    for(fahr = 0; fahr < upper; fahr += step){
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d %6d\n", fahr, celsius);
    }
}
