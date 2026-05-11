#include <stdio.h>
#include <stdlib.h>

int enteros[5];

int main() {
  for (int i = 0; i < 5; i++) {
    enteros[i] = ((rand()) % 21) - 10;
    printf("%3d\n", enteros[i]);
  }
  return 0;
}
