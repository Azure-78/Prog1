#include <stdio.h>
#include <stdlib.h>

int n_integer = 0;
int *mallocenteros;

int randomnumbs(int n);

int size();

int main() {
  n_integer = size();
  mallocenteros = (int *)malloc(n_integer * sizeof(int));
  randomnumbs(n_integer);

  free(mallocenteros);
  return 0;
}

int randomnumbs(int n) {
  for (int i = 0; i < n_integer; i++) {
    mallocenteros[i] = ((rand()) % 21) - 10;
    printf("%d\n", mallocenteros[i]);
  }
  return 1;
}

int size() {
  int input = 0;
  while (input < 1 || input > 10) {
    printf("Enter an integer [1-10]: ");
    scanf(" %d", &input);
  }
  return input;
}
