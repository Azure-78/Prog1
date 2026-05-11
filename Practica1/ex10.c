#include <math.h>
#include <stdio.h>

float b;
float h;

int main() {
  fprintf(stdout, "\nEnter the base: ");
  fscanf(stdin, "%f", &b);
  fprintf(stdout, "\nEnter the height: ");
  fscanf(stdin, "%f", &h);
  float p = sqrt((h * h) + (b * b));
  fprintf(stdout,
          "\n%-12s: %10.2f cm\n"
          "%-12s: %10.2f cm\n"
          "%-12s: %10.2f cm x cm\n"
          "%-12s: %10.2f cm\n",
          "Base", b, "Height", h, "Area", (b * h) / 2, "Perimeter", p + b + h);
  return 0;
}
