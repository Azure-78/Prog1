#include <ctype.h>
#include <stdio.h>

int returned = 0;

void boundary(char signo) {
  for (int i = 0; i < 50; i++) {
    printf("%c", signo);
  }
  printf("\n");
}

void mark() {
  boundary('-');
  printf("TELEVOTO\n");
  boundary('c');
}

int main() { mark(); }
