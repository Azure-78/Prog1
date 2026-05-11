#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "access.h"
#include "database.h"


char input;
int confirm_exit = 0;
int confirm_sure = 0;

int main() {
  struct Country countries[50];
  int numCountries;

  p_init (countries, &numCountries);

  do {
    mark("TELEVOTO");

    fprintf(stdout,
            "\nN) New Country\nR) Remove Country\nS) Show Countries\nA) "
            "Add Vote\nL) List Votes\nX) Exit\n");
    input = take_char("Enter Operation", "NRSALX");

    switch (input) {
    case 'N':
      p_new();
      break;
    case 'R':
      p_remove();
      break;
    case 'S':
      p_show(countries, numCountries);
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

