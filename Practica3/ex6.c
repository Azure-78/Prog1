#include <ctype.h>
#include <stdio.h>
#include <string.h>

char letra;

int main() {
  do {
    fprintf(stdout, "Introduzca un caracter: ");
    fscanf(stdin, " %c", &letra);
    if (strchr("nrsalx", letra) || strchr("NRSALX", letra)) {
      fprintf(stdout, "Letter %c, capitalised is: %c\n", letra, toupper(letra));
    }
  } while (!(strchr("nrsalx", letra) || strchr("NRSALX", letra)));
  return 0;
}
