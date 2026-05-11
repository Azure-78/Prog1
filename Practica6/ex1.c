#include <stdio.h>

int main() {
  int a;
  int *b;

  b = &a;
  a = 5;

  printf("value of a: %d\n", a);

  *b = 7;
  printf("value of a: %d\n", a);

  return 0;
}
