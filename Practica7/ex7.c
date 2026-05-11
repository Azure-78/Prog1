#include <stdio.h>

int main() {
  FILE *f;
  char linea[100], texto[50], basura_c[50];
  int basura_i;
  float basura_f;
  int entero;
  float real;

  f = fopen("format.txt", "r");

  if (f == NULL) {
    printf("File format.txt not accessible\n");
    return 1;
  }

  while (fgets(linea, 100, f) != NULL) {
    if (sscanf(linea, "%s %d %f %s %d %f", texto, &entero, &real, basura_c,
               &basura_i, &basura_f) == 3) {
      printf("\nString: %s\n", texto);
      printf("Integer: %d\n", entero);
      printf("Real: %.2f\n\n", real);
    } else {
      printf("Wrong format: %s", linea);
    }
  }

  fclose(f);
  return 0;
}
