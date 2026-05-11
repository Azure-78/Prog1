#include <stdio.h>

int number;

int main() {
  fprintf(stdout, "Enter the number of lines: ");
  fscanf(stdin, "%d", &number);

  for (int i = 0; i < number; i++) {
    for (int c = 0; c < 50; c++)
      fprintf(stdout, "-");
    fprintf(stdout, "\n");
  }
  return 0;
}
