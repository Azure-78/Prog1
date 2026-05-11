#include <stdio.h>
#include <string.h>

char str[50];

int main() {
  fprintf(stdout, "Enter a word: ");
  fscanf(stdin, "%s", str);
  int x = strlen(str);
  fprintf(stdout, "The string is %d characters long\n", x);
  return 0;
}
