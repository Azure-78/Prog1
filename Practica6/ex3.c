#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int get_size();

int main() {
  unsigned int size = get_size();
  int *enteros = malloc(sizeof(int) * size); 
  if(enteros == NULL) return -1;
  
  srand((unsigned int)time(NULL));
  for (unsigned int i = 0; i < size; i++) {
    enteros[i] = ((rand() % 21) - 10);
    printf("%3d\n", enteros[i]);
  }
  free(enteros);
  return 0;
}

unsigned int get_size(){
  unsigned int x;
  do {
    fprintf(stdout, "Enter an integer [1 - 10]: ");
    fscanf(stdin, "%u", &x);
    if (x >= 1 && x <= 10){
      break;
    }
  } while (x < 1 || x > 10);
  return x;
  }

