#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "access.h"
#include "database.h"

static struct Country *country_append(struct Country **list_c, const char *name, int code) {
  struct Country *node = malloc(sizeof(struct Country));
  if (node == NULL) return NULL;
  strcpy(node->name, name);
  node->code = code;
  node->next = NULL;
  if (*list_c == NULL) {
    *list_c = node;
  } else {
    struct Country *pos = *list_c;
    while (pos->next != NULL) pos = pos->next;
    pos->next = node;
  }
  return node;
}

static struct Vote *vote_append(struct Vote **list_v, int number, const char *voter, const char *voted, int points) {
  struct Vote *node = malloc(sizeof(struct Vote));
  if (node == NULL) return NULL;
  node->number = number;
  strcpy(node->voter, voter);
  strcpy(node->voted, voted);
  node->points = points;
  node->next = NULL;
  if (*list_v == NULL) {
    *list_v = node;
  } else {
    struct Vote *pos = *list_v;
    while (pos->next != NULL) pos = pos->next;
    pos->next = node;
  }
  return node;
}

int p_new(struct Country **list_c) {
  printf("New\n\n");
  char str[16];
  take_string("Name (1-15 char)", str);
  int code = take_int("Code [1-500]", 500);
  struct Country *node = country_append(list_c, str, code);
  if (node == NULL) return 1;
  printf("Country: %s;%d\n", node->name, node->code);
  return 0;
}

int p_show(struct Country *list_c) {
  printf("Countries:\n");
  struct Country *pos = list_c;
  while (pos != NULL) {
    printf("%s;%d\n", pos->name, pos->code);
    pos = pos->next;
  }
  return 0;
}

int p_remove(struct Country **list_c) {
  printf("Remove country\n");
  if (*list_c == NULL) {
    printf("No countries yet\n");
    return 0;
  }
  printf("\n");
  char str[16];
  take_string("Name (1-15 char)", str);
  struct Country *pos = *list_c;
  struct Country *prev = NULL;
  while (pos != NULL) {
    if (strcmp(pos->name, str) == 0) {
      if (prev == NULL) {
        *list_c = pos->next;
      } else {
        prev->next = pos->next;
      }
      free(pos);
      printf("Removed country\n");
      return 0;
    }
    prev = pos;
    pos = pos->next;
  }
  printf("Unknown country\n");
  return 0;
}

int p_add(struct Vote **list_v, int *n_v) {
  printf("Add vote\n\n");
  char voter[16];
  char voted[16];
  int number = *n_v + 1;
  take_string("Voter (1-15 char)", voter);
  take_string("Voted (1-15 char)", voted);
  int points = take_int("Points [1-12]", 12);
  struct Vote *node = vote_append(list_v, number, voter, voted, points);
  if (node == NULL) return 1;
  (*n_v)++;
  printf("Vote: %s;%s;%d\n", node->voter, node->voted, node->points);
  return 0;
}

int p_list(struct Vote *list_v) {
  printf("Votes:\n");
  struct Vote *pos = list_v;
  while (pos != NULL) {
    printf("%d;%s;%s;%d\n", pos->number, pos->voter, pos->voted, pos->points);
    pos = pos->next;
  }
  return 0;
}

int p_init(struct Country **list_c, struct Vote **list_v, int *n_v) {
  *list_c = NULL;
  *list_v = NULL;
  *n_v = 0;

  int code;
  char str[16];

  FILE *filecountries;
  if ((filecountries = fopen("countries.txt", "r")) != NULL) {
    while (fscanf(filecountries, "%15s %d", str, &code) == 2) {
      if (country_append(list_c, str, code) == NULL) {
        fclose(filecountries);
        return 1;
      }
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
      if (vote_append(list_v, number, voter, voted, points) == NULL) {
        fclose(filevotes);
        return 1;
      }
      (*n_v)++;
    }
    fclose(filevotes);
  }

  return 0;
}

int p_end(struct Country *list_c, struct Vote *list_v) {
  FILE *filecountries;
  if ((filecountries = fopen("countries.txt", "w")) == NULL) return 1;
  struct Country *pos_c = list_c;
  while (pos_c != NULL) {
    fprintf(filecountries, "%s %d\n", pos_c->name, pos_c->code);
    pos_c = pos_c->next;
  }
  fclose(filecountries);

  FILE *filevotes;
  if ((filevotes = fopen("votes.txt", "w")) == NULL) return 1;
  struct Vote *pos_v = list_v;
  while (pos_v != NULL) {
    fprintf(filevotes, "%d %s %s %d\n", pos_v->number, pos_v->voter, pos_v->voted, pos_v->points);
    pos_v = pos_v->next;
  }
  fclose(filevotes);
  return 0;
}
