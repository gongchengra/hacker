#include <stdio.h>
main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("celsius\tfahr\n");
    while (celsius < upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        //printf("%f\t%f\n", fahr, celsius);
        printf("%6.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
