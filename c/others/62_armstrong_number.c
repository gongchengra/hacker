#include <stdio.h>
int countDigit(int n){
    int c = 0;
    while(n != 0){
        n /= 10;
        ++c;
    }
    return c;
}
int isArmstrong(int n) {
    int c = countDigit(n);
    int remainder, result = 0, pow, ori = n;
    while(n != 0){
        remainder = n %10;
        pow = 1;
        for(int i = 0; i< c; i++){
            pow *= remainder;
        }
        result += pow;
        n /= 10;
    }
    if(result == ori) {
        return 1;
    } else {
        return 0;
    }
}
int main(int argc, char **argv){
    for(int i = 1; i < 100000; i++){
        if(isArmstrong(i) == 1) {
            printf("%7d", i);
        }
    }
    return 0;
}
