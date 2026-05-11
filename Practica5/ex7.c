#include <ctype.h>
#include <stdio.h>

char input;
int confirm_exit = 0;
int confirm_sure = 0;

void boundary(char signo);

void mark(char mark_input[50]);

int validate(char validate_input[15]);

int p_new() {
  printf("New\n");
  return 0;
}

int p_show() {
  printf("Show\n");
  return 0;
}

int p_remove() {
  printf("Remove\n");
  return 0;
}

int p_add() {
  printf("Add\n");
  return 0;
}

int p_list() {
  printf("List\n");
  return 0;
}

int main() {
  do {
    mark("TELEVOTO");

    fprintf(stdout,
            "\nN) New Country\nR) Remove Country\nS) Show Countries\nA) "
            "Add Vote\nL) List Votes\nX) Exit\n");

    fprintf(stdout, "\nEnter operation: ");
    fscanf(stdin, " %c", &input);

    switch (toupper(input)) {
    case 'N':
      p_new();
      break;
    case 'R':
      p_remove();
      break;
    case 'S':
      p_show();
      break;
    case 'A':
      p_add();
      break;
    case 'L':
      p_list();
      break;
    case 'X':
      if (validate("Confirm Exit")) {
        confirm_sure = validate("Sure");
      }
      break;
    default:
      fprintf(stdout, "\nInvalid option\n");
      break;
    }
  } while (!(confirm_sure));
  return 0;
}

void boundary(char signo) {
  for (int i = 0; i < 50; i++) {
    printf("%c", signo);
  }
  printf("\n");
}

void mark(char mark_input[50]) {
  boundary('.');
  printf("%s\n", mark_input);
  boundary('*');
}

int validate(char validate_input[15]) {
  char confirm_validate;
  do {
    printf("%s? (YN): ", validate_input);
    scanf(" %c", &confirm_validate);
  } while (toupper(confirm_validate) != 'Y' &&
           toupper(confirm_validate) != 'N');
  return (toupper(confirm_validate) == 'Y');
}
