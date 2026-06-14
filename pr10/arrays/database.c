#include <stdio.h>
#include <string.h>
#include "access.h"
#include "database.h"

int p_new(struct Country *tab_c, int *n_c) {
  printf("New\n\n");
  char str[16];
  take_string("Name (1-15 char)", str);
  tab_c[*n_c].code = take_int("Code [1-500]", 500);
  strcpy(tab_c[*n_c].name, str);
  (*n_c)++;
  printf("Country: %s;%d\n", tab_c[*n_c - 1].name, tab_c[*n_c - 1].code);
  return 0;
}

int p_show(struct Country *tab_c, int *n_c) {
  printf("Countries:\n");
  for (int i = 0; i < *n_c; i++) {
    printf("%s;%d\n", tab_c[i].name, tab_c[i].code);
  }
  return 0;
}

int p_remove(struct Country *tab_c, int *n_c) {
  printf("Remove country\n");
  if (*n_c == 0) {
    printf("No countries yet\n");
    return 0;
  }
  printf("\n");
  char str[16];
  take_string("Name (1-15 char)", str);
  for (int i = 0; i < *n_c; i++) {
    if (strcmp(tab_c[i].name, str) == 0) {
      for (int j = i; j < *n_c - 1; j++) {
        tab_c[j] = tab_c[j + 1];
      }
      (*n_c)--;
      printf("Removed country\n");
      return 0;
    }
  }
  printf("Unknown country\n");
  return 0;
}

int p_add(struct Vote *tab_v, int *n_v) {
  printf("Add vote\n\n");
  char str[16];
  tab_v[*n_v].number = *n_v + 1;
  take_string("Voter (1-15 char)", str);
  strcpy(tab_v[*n_v].voter, str);
  take_string("Voted (1-15 char)", str);
  strcpy(tab_v[*n_v].voted, str);
  tab_v[*n_v].points = take_int("Points [1-12]", 12);
  (*n_v)++;
  printf("Vote: %s;%s;%d\n", tab_v[*n_v - 1].voter, tab_v[*n_v - 1].voted, tab_v[*n_v - 1].points);
  return 0;
}

int p_list(struct Vote *tab_v, int n_v) {
  printf("Votes:\n");
  for (int i = 0; i < n_v; i++) {
    printf("%d;%s;%s;%d\n", tab_v[i].number, tab_v[i].voter, tab_v[i].voted, tab_v[i].points);
  }
  return 0;
}

int p_init(struct Country *tab_c, int *n_c, struct Vote *tab_v, int *n_v) {
  *n_c = 0;
  *n_v = 0;

  int code;
  char str[16];

  FILE *filecountries;
  if ((filecountries = fopen("countries.txt", "r")) != NULL) {
    while (fscanf(filecountries, "%15s %d", str, &code) == 2) {
      strcpy(tab_c[*n_c].name, str);
      tab_c[*n_c].code = code;
      (*n_c)++;
    }
    fclose(filecountries);
  }

  int number;
  char voter[16];
  char voted[16];
  int points;

  FILE *filevotes;
  if ((filevotes = fopen("votes.txt", "r")) != NULL) {
    while (fscanf(filevotes, "%d %15s %15s %d", &number, voter, voted, &points) == 4) {
      tab_v[*n_v].number = number;
      strcpy(tab_v[*n_v].voter, voter);
      strcpy(tab_v[*n_v].voted, voted);
      tab_v[*n_v].points = points;
      (*n_v)++;
    }
    fclose(filevotes);
  }

  return 0;
}

int p_end(struct Country *countries, int numCountries, struct Vote *votes, int numVotes) {
  FILE *filecountries;
  if ((filecountries = fopen("countries.txt", "w")) == NULL) return 1;
  for (int i = 0; i < numCountries; i++) {
    fprintf(filecountries, "%s %d\n", countries[i].name, countries[i].code);
  }
  fclose(filecountries);

  FILE *filevotes;
  if ((filevotes = fopen("votes.txt", "w")) == NULL) return 1;
  for (int i = 0; i < numVotes; i++) {
    fprintf(filevotes, "%d %s %s %d\n", votes[i].number, votes[i].voter, votes[i].voted, votes[i].points);
  }
  fclose(filevotes);
  return 0;
}
