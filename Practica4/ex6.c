#include <stdio.h>

unsigned int id;
char name[30];

int main() {
  printf("Enter a line with the format "
         "ID name"
         ": ");
  scanf(" %d %s", &id, name);
  printf("ID: %u\nName: %s\n", id, name);
  return 0;
}
