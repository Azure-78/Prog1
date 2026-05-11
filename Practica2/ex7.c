#include <stdio.h>

float numero1;
float numero2;
char operacion;

int main() {
  fprintf(stdout, "Enter an operation: ");
  fscanf(stdin, " %f %c %f", &numero1, &operacion, &numero2);

  switch (operacion) {
  case '+':
    fprintf(stdout, "\nResult: %.2f\n", numero1 + numero2);
    break;
  case '-':
    fprintf(stdout, "\nResult: %.2f\n", numero1 - numero2);
    break;
  case '*':
    fprintf(stdout, "\nResult: %.2f\n", numero1 * numero2);
    break;
  case '/':
    fprintf(stdout, "\nResult: %.2f\n", numero1 / numero2);
    break;
  default:
    fprintf(stdout, "\nNot valid\n");
    break;
  }
  return 0;
}
