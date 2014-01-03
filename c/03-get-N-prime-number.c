#include <stdio.h>
#include <math.h>
#define Numbers 10000

int getFirstNPrimeNumbers(int N) {
	int resultArray[N];
    int i,j;
    int intN = N;
    if(intN < 1) {
        resultArray[0] = '0';
    } else if (intN == 1) {
        resultArray[0] = '2';
    } else {
        //According to Prime_number_theorem,
        //the N prime number is approximately N*ln(N),
        //in order to make sure we can get N numbers, we multiply by a factor 1.2
        long maxNumber;
        if(intN < 20) {
            long maxNumber = ceil(3*intN*log(intN));
        } else {
            long maxNumber = ceil(1.2*intN*log(intN));
        }
        printf("%ld", maxNumber);
        char primeArray[maxNumber];
        for (i=0; i<maxNumber; i++) {
            primeArray[i] = 't';
        }
        float sqrtMax = sqrt(maxNumber);
        for(i=0;i<=sqrtMax;i++) {
            if(primeArray[i] == 't') {
                for(j=i+2;j<maxNumber;j++){
                    if((j+2)%(i+2) == 0) {
                        primeArray[j] = 'f';
                    }
                }
            }
        }
        j = 0;
        for(i=0;i<maxNumber,j<N;i++) {
            if(primeArray[i] == 't') {
                resultArray[j] = i+2;
                j++;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d ,", resultArray[i]);
    }
}

int main()
{
    getFirstNPrimeNumbers(10);
/*    int resultArray[Numbers];*/
/*    int i,j;*/
/*    long maxNumber = 1.2*Numbers*log(Numbers);*/
/*    char primeArray[maxNumber];*/
/*    float sqrtMax = sqrt(maxNumber);*/
/*    for (i=0; i<maxNumber; i++) {*/
/*        primeArray[i] = 't';*/
/*    }*/
/*    for(i=0;i<=sqrtMax;i++) {*/
/*        if(primeArray[i] == 't') {*/
/*            for(j=i+2;j<maxNumber;j++){*/
/*                if((j+2)%(i+2) == 0) {*/
/*                    primeArray[j] = 'f';*/
/*                }*/
/*            }*/
/*        }*/
/*    }*/
/*    j = 0;*/
/*    for(i=0;i<maxNumber,j< Numbers;i++) {*/
/*        if(primeArray[i] == 't') {*/
/*            resultArray[j] = i+2;*/
/*            j++;*/
/*        }*/
/*    }*/
/*    for(i=0;i<Numbers;i++){*/
/*        printf("%d ,", resultArray[i]);*/
/*    }*/
/*    printf("\n");*/
}
