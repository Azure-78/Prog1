#include <stdio.h>

int input_e = 0;
char input_c[50];
float input_r;

FILE *file;

int get();

int main() { get(); }

int get() {
  if ((file = fopen("format.txt", "w")) == NULL)
    return 1;
  while (input_e >= 0) {
    printf("Enter an integer: ");
    scanf(" %d", &input_e);
    if (input_e < 0)
      break;
    printf("\nEnter a string: ");
    scanf(" %s", input_c);
    printf("\nEnter a real number: ");
    scanf(" %f", &input_r);

    fprintf(file, "%d", input_e);
    fprintf(file, " %s", input_c);
    fprintf(file, " %.2f", input_r);
  }

  fclose(file);

  return 0;
}
