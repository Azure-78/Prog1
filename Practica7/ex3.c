#include <stdio.h>

char character;
char text_file[20] = "character.txt";
int contador = 0;

FILE *fichero_a;
FILE *fichero_b;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./ex3 file_name\n");
    return 1;
  }
  fichero_a = fopen(argv[1], "r");
  if (fichero_a == NULL) {
    printf("File not found\n");
    return 1;
  }
  fichero_b = fopen(text_file, "w");

  while ((character = fgetc(fichero_a)) != EOF) {
    fputc(character, fichero_b);
    contador++;
  }
  fclose(fichero_a);
  fclose(fichero_b);
  fprintf(stdout, "%d caracteres.\n", contador);
  return 0;
}
