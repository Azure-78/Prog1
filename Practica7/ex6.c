#include <stdio.h>

int main() {
  FILE *f;
  char linea[100], texto[50];
  int entero;
  float real;

  f = fopen("format.txt", "r");

  if (f == NULL) {
    printf("File format.txt not accessible\n");
    return 1;
  }

  while (fgets(linea, 100, f) != NULL) {
    if (sscanf(linea, "%s %d %f", texto, &entero, &real) == 3) {
      printf("String: %s\n", texto);
      printf("Integer: %d\n", entero);
      printf("Real: %.2f\n", real);
    }
  }

  fclose(f);
  return 0;
}
