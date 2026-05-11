#include <stdio.h>
#include <stdlib.h>
int main(void) {
  char name[] = "Jacobo";
  char *ps1 = &name[0];
  char *ps2 = name;
  int *pi1, *pi2, i;
  if (ps1 == ps2)
    printf("ps1 is equal to ps2\n");
  else
    printf("ps1 is different from ps2\n");

  ps1[0] = 'X';
  *(ps2 + 5) = 'e';
  printf("The name is: %s\n", name);

  pi1 = malloc(5 * sizeof(int));
  pi2 = pi1;

  for (i = 0; i < 5; i++)
    pi1[i] = i * 10 + 1;
  for (i = 0; i < 5; i++)
    printf("%d ", pi1[i]);

  printf("\n");
  *(pi2 + 2) *= 5;
  pi2 += 3;

  printf("pi1[2] = %d\n", pi1[2]);
  printf("pi2 points to %d\n", *pi2);
  printf("There are %ld ints between pi1 and pi2\n", pi2 - pi1);
  printf("Value of *pi2 - *pi1: %d\n", *pi2 - *pi1);
  return 0;
}
