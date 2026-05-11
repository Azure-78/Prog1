#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "access.h"

char take_char(const char *prompt, const char *pattern);

int take_int(const char *prompt, int maximum);

void take_string(const char *prompt, char *string);

void boundary(char signo, int n_chars);

void mark(char mark_input[50]);

int validate(char validate_input[15]);

void boundary(char signo, int n_chars) {
  for (int i = 0; i < n_chars; i++) {
    printf("%c", signo);
  }
  printf("\n");
}

void mark(char mark_input[50]) {
  boundary('.', 50);
  printf("%s\n", mark_input);
  boundary('*', 50);
}

int validate(char validate_input[15]) {
  if (take_char(validate_input, "YN") == 'Y') {
    return 1;
  } else {
    return 0;
  }
}

void take_string(const char *prompt, char *string) {
  int x;
  do {
    fprintf(stdout, "%s: ", prompt);
    fscanf(stdin, "%s", string);

    x = strlen(string);

    if (x == 0 || x > 49) {
      continue;
    } else {
      break;
    }
  } while (x != 0 && x < 49);
}

int take_int(const char *prompt, int maximum) {
  int int_input = 0;
  do {
    fprintf(stdout, "%s: ", prompt);
    fscanf(stdin, "%d", &int_input);
    if (int_input >= 0 && int_input <= maximum) {
      fprintf(stdout, "\n%d\n", int_input);
      break;
    }
  } while (int_input < 0 || int_input > maximum);
  return int_input;
}

char take_char(const char *prompt, const char *pattern) {
  char letra;
  do {
    fprintf(stdout, "%s [%s]: ", prompt, pattern);
    fscanf(stdin, " %c", &letra);
    if (strchr(pattern, letra) || strchr(pattern, toupper(letra))) {
      break;
    }
  } while (!(strchr(pattern, letra) || strchr(pattern, toupper(letra))));
  return toupper(letra);
}
