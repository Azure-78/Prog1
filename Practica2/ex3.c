#include <math.h>
#include <stdio.h>

float x;

int main() {
  fprintf(stdout, "Enter an integer [0 - 100]: ");
  fscanf(stdin, "%f", &x);
  if (x < 0 || x > 100) {
    fprintf(stdout, "\nWrong value\n");
  } else {
    fprintf(stdout, "\nRoot: %10.2f\n", sqrt(x));
  }
  return 0;
}
