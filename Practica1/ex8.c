#include <ctype.h>
#include <stdio.h>

char letra;

int main() {
  fprintf(stdout, "Introduzca un caracter: ");
  fscanf(stdin, "%c", &letra);
  fprintf(stdout, "Letter %c, capitalised is: %c\n", letra, toupper(letra));
}
