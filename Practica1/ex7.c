#include <math.h>
#include <stdio.h>

float x;

int main() {
  fprintf(stdout, "Enter an integer: ");
  fscanf(stdin, "%f", &x);
  fprintf(stdout, "\nRoot: %10.2f\n", sqrtf(x));
  return 0;
}
