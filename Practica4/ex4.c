#include <stdio.h>
#include <stdlib.h>

int enteros[3][5];

int main() {
  for (int x = 0; x < 5; x++) {
    for (int i = 0; i < 3; i++) {
      enteros[i][x] = ((rand()) % 21) - 10;
      printf("%3d", enteros[i][x]);
    }
    printf("\n");
  }
  return 0;
}
