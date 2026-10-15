#include <stdio.h>

int main(){


  char team_letter;

  printf("Enter a character: ");
  scanf("%c", &team_letter);
  printf("Character entered is: %c\n", team_letter);


  switch (team_letter){
    case 'A':
      printf("Alabama \n");
      break;

    case 'B':
      printf("Baylor \n");
      break;

    case 'C':
      printf("CCSU\n");
      break;

    case 'N':
      printf("Nebraska \n");
      break;

    default:
      printf("Letter entered invalid\n");
      
  }
  return 0;
}
