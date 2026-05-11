#include <math.h>
#include <stdio.h>

float x;

int main() {
  do {
    fprintf(stdout, "Enter an integer [0 - 100]: ");
    fscanf(stdin, "%u", &x);
    if (x >= 0 && x <= 100) {
      fprintf(stdout, "\nRoot: %10.2f\n", sqrt(x));
      break;
    }
  } while (x < 0 || x > 100);
  return 0;
}
