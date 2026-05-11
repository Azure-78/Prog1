#include <stdio.h>
#include <string.h>

char str[15];

int main() {
  fprintf(stdout, "Enter a word (1 - 15 chars): ");
  fscanf(stdin, "%s", str);
  int x = strlen(str);
  if (x == 0 || x > 15) {
    fprintf(stdout, "Null or excessive length\n");
  } else {
    fprintf(stdout, "The string is %d characters long\n", x);
  }
  return 0;
}
