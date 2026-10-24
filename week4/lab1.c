#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(int);

int main(int argc, char *argv[]) {
  int x;
  printf("Enter a positive integer: ");
  scanf("%d", &x);
  printf("\n");

  while (x < 0) {
    printf("Enter a positive integer: ");
    scanf("%d", &x);
  }

  fizzbuzz(x);

  return EXIT_SUCCESS;
}

void fizzbuzz(int userInput) {

  for (int i = 1; i < userInput + 1; i++) {

    if (i % 3 == 0 && i % 5 == 0) {
      printf("Fizzbuzz\n");
    } else if (i % 3 == 0) {
      printf("Fizz\n");
    } else if (i % 5 == 0) {
      printf("Buzz\n");
    } else {
      printf("%d\n", i);
    }
  }
}
