#include <stdio.h>
#include <math.h>
#include <gmp.h>
// gcc -lgmp 60_pow_func.c -o 60_pow_func.exe
void mypow(double base, double exp){
    mpz_t r;
    int b = (int) base;
    int e = (int) exp;
    mpz_init_set_ui(r, 1);
    while(e != 0){
        mpz_mul_ui(r, r, b);
        --e;
    }
    printf("%d ^ %d = ", b, e);
    mpz_out_str(stdout,10,r);
    printf("\n");
    mpz_clear(r);
}
int main(int argc, char **argv){
    double base, exp, result;
    printf("Input base number: ");
    scanf("%lf", &base);
    printf("Input exponent number: ");
    scanf("%lf", &exp);
    result = pow(base, exp);
    printf("%lf^%lf = %lf\n", base, exp, result);
    mypow(base, exp);
    return 0;
}
