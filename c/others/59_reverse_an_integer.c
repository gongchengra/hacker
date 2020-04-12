#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
    if(argc < 2) {
        printf("Usage: Input an integer abcd, %s will output dcba.\n", argv[0]);
    }else{
        int remainder;
        long long n = atoll(argv[1]), rev=0;
        while(n != 0){
            remainder = n % 10;
            rev = rev * 10 + remainder;
            n /= 10;
        }
        printf("Reverse %s will be %lld.\n", argv[1], rev);
    }
    return 0;
}
