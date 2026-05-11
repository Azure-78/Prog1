#include <ctype.h>
#include <stdio.h>

int returned = 0;

void mark() { printf("Hello World\n"); }

int validate() {
  char confirm;
  do {
    mark();
    printf("Confirm exit? (YN): ");
    scanf(" %c", &confirm);
  } while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');
  return (toupper(confirm) == 'Y');
}

int main() {
  int confirm_exit = 0;
  while (!confirm_exit) {
    confirm_exit = validate();
  }
}
