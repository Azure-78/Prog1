#include <ctype.h>
#include <stdio.h>
#include <string.h>

char letra;

int main() {
  fprintf(stdout, "Introduzca un caracter: ");
  fscanf(stdin, "%c", &letra);
  if (strchr("nrsalx", letra) || strchr("NRSALX", letra)) {
    fprintf(stdout, "Letter %c, capitalised is: %c\n", letra, toupper(letra));
  } else {
    fprintf(stdout, "Not valid\n");
  }
}
