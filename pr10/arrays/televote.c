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
  struct Vote votes[500];
  int numCountries;
  int numVotes;

  p_init (countries, &numCountries, votes, &numVotes);

  mark("TELEVOTE");

  do {
    fprintf(stdout,
            "\nN) New country\nR) Remove country\nS) Show countries\nA) "
            "Add vote\nL) List votes\nX) Exit\n\n");
    input = take_char("Enter operation", "NRSALX");

    switch (input) {
    case 'N':
      p_new(countries, &numCountries);
      break;
    case 'R':
      p_remove(countries, &numCountries);
      break;
    case 'S':
      p_show(countries, &numCountries);
      break;
    case 'A':
      p_add(votes, &numVotes);
      break;
    case 'L':
      p_list(votes, numVotes);
      break;
    case 'X':
      confirm_sure = validate("Confirm exit?");
      if (confirm_sure) {
        p_end(countries, numCountries, votes, numVotes);
      }
      break;
    default:
      fprintf(stdout, "\nInvalid option\n");
      break;
    }
  } while (!(confirm_sure));
  return 0;
}

