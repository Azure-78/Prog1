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
  boundary('-', 50);
  printf("%s\n", mark_input);
  boundary('-', 50);
}

int validate(char validate_input[15]) {
  if (take_char(validate_input, "YN") == 'Y') {
    return 1;
  } else {
    return 0;
  }
}

void take_string(const char *prompt, char *string) {
  char cadena_str[256];
  char extra_str[256];
  int x;
  while(1){
    fprintf(stdout, "%s: ", prompt);
    fgets(cadena_str, sizeof(cadena_str), stdin);
    if(sscanf(cadena_str, " %s%s", string, extra_str) == 1){
        x = strlen(string);
        if(x < 16) {
        break;
      }
    }
  }
}

int take_int(const char *prompt, int maximum) {
  char cadena_int[256];
  char extra_int[256];
  int int_input = 0;
  while(1){
    fprintf(stdout, "%s: ", prompt);
    fgets(cadena_int, sizeof(cadena_int), stdin);
    if(sscanf(cadena_int, " %d%s", &int_input, extra_int) == 1){
      if (int_input >= 1 && int_input <= maximum) {
        return int_input;
      }
    }
  }
}

char take_char(const char *prompt, const char *pattern) {
  char cadena_char[256];
  char extra_char[256];
  char choice;
  while (1){
    fprintf(stdout, "%s [%s]: ", prompt, pattern);
    fgets(cadena_char, sizeof(cadena_char), stdin);
    if(sscanf(cadena_char, " %c%s", &choice, extra_char) == 1){
      if (strchr(pattern, choice) || strchr(pattern, toupper(choice))){
        return toupper(choice);
      }
    }
  }
}
