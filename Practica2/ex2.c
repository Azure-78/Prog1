#include <stdio.h>

char opcion;

int main() {
  fprintf(stdout, "Confirm exit? (YN) : ");
  fscanf(stdin, "%c", &opcion);

  if (opcion == 'Y' || opcion == 'y') {
    fprintf(stdout, "You have chosen: "
                    "Yes\n");
  } else {
    fprintf(stdout, "You have chosen: "
                    "No\n");
  }
  return 0;
}
