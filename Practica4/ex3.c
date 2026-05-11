#include <ctype.h>
#include <stdio.h>

char input;
int confirm = 0;

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
      do {
        printf("Confirm exit? (YN): ");
        scanf(" %c", &input);
        if (toupper(input) == 'Y' || toupper(input) == 'N') {
          if (toupper(input) == 'Y') {
            confirm = 1;
            break;
          } else {
            confirm = 0;
            break;
          }
        } else {
          continue;
        }
      } while (toupper(input) != 'Y' || toupper(input) != 'N');
      break;
    default:
      fprintf(stdout, "\nInvalid option\n");
      break;
    }
  } while (!(confirm));
  return 0;
}
