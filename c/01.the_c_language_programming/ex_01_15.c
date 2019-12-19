#include <stdio.h>

float fahr2celcius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32);
}

int main() {

    int fahr;

    printf("fahr celcius\n");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, fahr2celcius(fahr));
    }

    return 0;

}
