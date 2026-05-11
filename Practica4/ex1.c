#include <stdio.h>

int enteros[5];

int main() {
  for (int i = 0; i < 5; i++) {
    enteros[i] = i * 10;
    printf("%3d\n", enteros[i]);
  }
  return 0;
}
