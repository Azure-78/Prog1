#include <stdio.h>
#include <string.h>

char str[15];
int x;

int main() {
  do {
    fprintf(stdout, "Enter a word (1 - 15 chars): ");
    fscanf(stdin, "%s", str);

    x = strlen(str);

    if (x == 0 || x > 15) {
      continue;
    } else {
      fprintf(stdout, "The string is %d characters long\n", x);
      break;
    }
  } while (x != 0 || x < 15);
  return 0;
}
