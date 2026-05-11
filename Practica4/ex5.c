#include <ctype.h>
#include <stdio.h>

char cadenas[5][26];
int positionletter;
int positionstring;

int main() {
  for (int i = 0; i < 5; i++) {
    fprintf(stdout, "Enter a string [1-25 chars]: ");
    scanf(" %25s", &cadenas[i][0]);
  }
  printf("\nPosition of the character to convert [1-25]: ");
  scanf(" %d", &positionletter);
  positionletter--;
  for (int x = 0; x < 5; x++) {
    cadenas[x][positionletter] = toupper(cadenas[x][positionletter]);
  }
  printf("\nPosition of the string to display [1-5]: ");
  scanf(" %d", &positionstring);
  positionstring--;
  printf("The string in position %d is %s\n", positionstring + 1,
         cadenas[positionstring]);


  return 0;
}
