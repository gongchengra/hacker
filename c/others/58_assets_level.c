#include <stdio.h>
int main() {
    long long n;
    int count = 0, level;
    printf("Enter how much money do you have: ");
    scanf("%lld", &n);
    while(n != 0){
        n /= 10;
        if(n > 0 && n < 10) level = n;
        ++count;
    }
/*    printf("Number of digits: %d", count);*/
    printf("You asset level is %d.%d\n", count, level);
}
