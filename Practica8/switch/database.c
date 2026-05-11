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
  *number = 0;
  code = take_int ("Code", 500);
  while (code > 0) {
    tab_c[*number].code = code;
    take_string ("Country", tab_c[*number].name);
    (*number)++ ;
    code = take_int ("Code", 500);
  }
  return 0;
}

