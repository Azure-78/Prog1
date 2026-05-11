#include <ctype.h>
#include <stdio.h>

char input;

int main() {
  do {
    fprintf(stdout,
            "\nN) New Country\nR) Remove Country\nS) Show Countries\nA) "
            "Add Vote\nL) List Votes\nX) Exit\n");

    fprintf(stdout, "\nEnter operation: ");
    fscanf(stdin, " %c", &input);

    switch (toupper(input)) {
    case 'N':
      fprintf(stdout, "\nNew\n");
      break;
    case 'R':
      fprintf(stdout, "\nRemove\n");
      break;
    case 'S':
      fprintf(stdout, "\nShow\n");
      break;
    case 'A':
      fprintf(stdout, "\nAdd\n");
      break;
    case 'L':
      fprintf(stdout, "\nList\n");
      break;
    case 'X':
      fprintf(stdout, "\nExit\n");
      break;
    default:
      fprintf(stdout, "\nInvalid option\n");
      break;
    }
  } while (toupper(input) != 'X');
  return 0;
}
