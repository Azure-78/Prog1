#include <stdio.h>

char opcion;

int main() {
  do {
    fprintf(stdout, "Confirm exit? (YN) : ");
    fscanf(stdin, " %c", &opcion);

    if (opcion == 'Y' || opcion == 'y') {
      fprintf(stdout, "You have chosen: "
                      "Yes\n");
    } else if (opcion == 'N' || opcion == 'n') {
      fprintf(stdout, "You have chosen: "
                      "No\n");
    }
  } while (!(opcion == 'Y' || opcion == 'y' || opcion == 'N' || opcion == 'n'));
  return 0;
}
