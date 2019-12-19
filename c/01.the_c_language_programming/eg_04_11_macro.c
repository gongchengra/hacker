#include <stdio.h>
#define forever for (;;) /* infinite loop */
#define max(a, b) ((a) > (b) ? (a) : (b))
#define dprint(expr) printf(#expr " = %g\n", expr)
int main() {
  int i = 0;
  forever {
    i++;
    printf("hell"
           "o world"
           "\n");
    if (i == 5)
      break;
  }
  printf("%d\n", max(100, 101));
  printf("1.0/3 "
         "= %g\n",
         1.0 / 3);
  dprint(1.0 / 3);
  return 100;
}
