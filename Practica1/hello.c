#include <stdio.h>

short x = 5;
short y = 4;

int main() {
  fprintf(stdout, "Hello World\n");
  if (x > 4 || y > 0 && x > 10) {
    fprintf(stdout, "X es %d, y Y es %d", x, y);
  }
  return 0;
}
