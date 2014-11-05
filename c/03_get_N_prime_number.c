#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Numbers 1000000

int *getPrimeNumbersLessthanN(int N, int *resultArray) {
    char primeArray[Numbers]={0};
    int i, j;
    for (i = 2; i <= sqrt(N); i++) {
        if (primeArray[i] == 0) {
            for (j = i + i; j < N; j += i) {
                primeArray[j] = 1;
            }
        }
    }
    for (i = 2,j = 0; i < N; i++) {
        if (primeArray[i] == 0) {
            resultArray[j] = i;
            j++;
        }
    }
    return 0;
}

int main(void)
{
    unsigned int i;
    int primes[Numbers]={0};
    getPrimeNumbersLessthanN(1000000, primes);
    for(i = 0; primes[i] != 0 && i < (sizeof(primes)/sizeof(int)); i++){
        printf("%7d", primes[i]);
        printf((i%10 == 9)?"\n":" ");
    }
    return 0;
}
