#include <stdio.h>
#include "access.h"
#include "database.h"


int p_new() {
  char str[50];
  printf("New\n");
  take_string("Country", str);
  return 0;
}

int p_show(struct Country *tab_c, int number) {
  printf("Show\nCountries:\n");
  for(int i = 0; i < number; i++){
    printf("%s;%d\n", tab_c[i].name, tab_c[i].code);
  }
  return 0;
}

int p_remove() {
  printf("Remove\n");
  return 0;
}

int p_add() {
  printf("Add\n");
  take_int("Vote", 12);
  return 0;
}

int p_list() {
  printf("List\n");
  return 0;
}

int p_init (struct Country *tab_c, int *number) {
  int code;
  char str[50];
  *number = 0;
  FILE *file;
  if ((file = fopen("countries.txt", "r")) == NULL) return 1;
  if (fscanf(file, "%49s %d", str, &code) != 2) return 1;
  while(code >= 0) {
    tab_c[*number].code = code;
    strcpy(tab_c[*number].name, str);
    if (fscanf(file, "%49s %d", str, &code) == EOF) break;
    (*number)++ ;
  }
  fclose(file);
  return 0;
}
