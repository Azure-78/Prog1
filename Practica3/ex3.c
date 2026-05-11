#include <stdio.h>

int limite;
int i;
long numero;

int main() {
  fprintf(stdout, "Enter the number of values: ");
  fscanf(stdin, "%d", &limite);

  while (i != limite) {

    fprintf(stdout, "Enter a real number: ");
    fscanf(stdin, "%ld", &numero);

    fprintf(stdout, "%ld squared = %ld\n", numero, numero * numero);
    i++;
  }
  return 0;
}
