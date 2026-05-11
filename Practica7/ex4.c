#include <stdio.h>

char line[100];
char *text_file = "character.txt";
int contador = 0;

FILE *fichero_a;
FILE *fichero_b;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./ex4 file_name\n");
    return 1;
  }
  fichero_a = fopen(argv[1], "r");
  if (fichero_a == NULL) {
    printf("File not found\n");
    return 1;
  }
  fichero_b = fopen(text_file, "w");

  while (fgets(line, 100, fichero_a) != NULL) {
    fputs(line, fichero_b);
    contador++;
  }
  fclose(fichero_a);
  fclose(fichero_b);
  fprintf(stdout, "%d lineas.\n", contador);
  return 0;
}
