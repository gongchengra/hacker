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

int *getNPrimeNumbers(int N, int *resultArray) {
    //According to Prime_number_theorem,
    //the N prime number is approximately N*ln(N),
    //in order to make sure we can get N numbers, we multiply by a factor 1.2
    unsigned long tmp;
    if(N < 1) {
        return 0;
    } else if (N < 20) {
        getPrimeNumbersLessthanN(3*log(N)*N, resultArray);
    } else {
        getPrimeNumbersLessthanN(1.2*log(N)*N, resultArray);
    }
    for(tmp = N; tmp < (sizeof(resultArray)/sizeof(int)); tmp++){
        resultArray[tmp] = 0;
    }
    return 0;
}

int main(void)
{
    unsigned int i;
    int primes[Numbers]={0};
    printf("The prime numbers less than 1000000 are listed: \n");
    getPrimeNumbersLessthanN(1000000, primes);
    for(i = 0; primes[i] != 0 && i < (sizeof(primes)/sizeof(int)); i++){
        printf("%7d", primes[i]);
        printf((i%10 == 9)?"\n":" ");
        primes[i] = 0;
    }
    printf("\nThe first 1000 prime numbers are listed: \n");
    getNPrimeNumbers(5, primes);
    for(i = 0; primes[i] != 0 && i < (sizeof(primes)/sizeof(int)); i++){
        printf("%7d", primes[i]);
        printf((i%10 == 9)?"\n":" ");
    }
    printf("\n");
    return 0;
}
