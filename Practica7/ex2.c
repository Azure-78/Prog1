#include <stdio.h>
#include <stdlib.h>

float rectangle(float base, float height, float *p_area);

int main(int argc, char *argv[]) {
  float area;
  if (argc == 3) {
    float b = atof(argv[1]);
    float h = atof(argv[2]);
    rectangle(b, h, &area);
  } else {
    printf("Usage: ./ex2 base height\n");
  }
}

float rectangle(float base, float height, float *p_area) {
  *p_area = base * height;
  float perimeter = 2 * (base * height);
  printf("%-12s: %10.2f\n%-12s: %10.2f\n%-12s: %10.2f\n%-12s: %10.2f\n", "Base",
         base, "Height", height, "Area", *p_area, "Perimeter", perimeter);
  return perimeter;
}
