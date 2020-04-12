#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
void fact(int n) {
    int i;
    mpz_t p;
    mpz_init_set_ui(p, 1);
    for (i = 1; i <= n; i++) {
        mpz_mul_ui(p, p, i);
    }
    printf("%d! = ", n);
    mpz_out_str(stdout, 10, p);
    printf("\n");
    mpz_clear(p);
}
int main(int argc, char **argv) {
#if 0
    mpz_t a, b;     /* working numbers */
    if (argc < 3) { /* not enough words */
        printf("Please supply two numbers to add.\n");
        return 1;
    }
    mpz_init_set_str(a, argv[1], 10); /* Assume decimal integers */
    mpz_init_set_str(b, argv[2], 10); /* Assume decimal integers */
    mpz_add(a, a, b);                 /* a=a+b */
    printf("%s + %s => %s\n", argv[1], argv[2], mpz_get_str(NULL, 10, a));
    return 0;
#endif
    char inputStr[1024];
    /*
     *      mpz_t is the type defined for GMP integers.
     *           It is a pointer to the internals of the GMP integer data
     * structure
     *              */
    mpz_t n;
    int flag;
    printf("Enter your number: ");
    scanf("%1023s",
          inputStr); /* NOTE: never every write a call scanf ("%s", inputStr);
                        You are leaving a security hole in your code. */
    /* 1. Initialize the number */
    mpz_init(n);
    mpz_set_ui(n, 0);
    /* 2. Parse the input string as a base 10 number */
    flag = mpz_set_str(n, inputStr, 10);
    assert(flag == 0); /* If flag is not 0 then the operation failed */
                       /* Print n */
    printf("n = ");
    mpz_out_str(stdout, 10, n);
    printf("\n");
    /* 3. Add one to the number */
    mpz_add_ui(n, n, 1); /* n = n + 1 */
    /* 4. Print the result */
    printf(" n +1 = ");
    mpz_out_str(stdout, 10, n);
    printf("\n");
    /* 5. Square n+1 */
    mpz_mul(n, n, n); /* n = n * n */
    printf(" (n +1)^2 = ");
    mpz_out_str(stdout, 10, n);
    printf("\n");
    /* 6. Clean up the mpz_t handles or else we will leak memory */
    mpz_clear(n);
    fact(atoi(inputStr));
}
