#include <stdio.h>
#include <limits.h>
int main()
{
  printf("sizeof(char) = %ld\n", sizeof(char));
  printf("Unsigned char: %d\t%d\n", 0, UCHAR_MAX);
  printf("Signed char: %d\t%d\n", SCHAR_MIN, SCHAR_MAX);

  printf("sizeof(short) = %ld\n", sizeof(short));
  printf("Unsigned short: %d\t%d\n", 0, USHRT_MAX);
  printf("(Signed) short: %d\t%d\n", SHRT_MIN, SHRT_MAX);

  printf("sizeof(int) = %ld\n", sizeof(int));
  printf("Unsigned int: %d\t%d\n", 0, UINT_MAX);
  printf("(Signed) int: %d\t%d\n", INT_MIN, INT_MAX);

  printf("sizeof(long) = %ld\n", sizeof(long));
  printf("Unsigned long: %d\t%ld\n", 0, ULONG_MAX);
  printf("(Signed) long: %ld\t%ld\n", LONG_MIN, LONG_MAX);

  printf("sizeof(long long) = %ld\n", sizeof(long long));
  printf("Unsigned long long: %d\t%lld\n", 0, ULLONG_MAX);
  printf("(Signed) long long: %lld\t%lld\n", LLONG_MIN, LLONG_MAX);

  printf("sizeof(float) = %ld\n", sizeof(float));
  printf("sizeof(double) = %ld\n", sizeof(double));
  printf("sizeof(long double) = %ld\n", sizeof(long double));

  return 0;
}
