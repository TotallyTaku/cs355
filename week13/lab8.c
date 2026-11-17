#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <stdbool.h>


bool isPrime(int);
void displayCurrentMaxPrime(int);

int main(int argc, char *argv[])
{
  int j =0;
  int prime = -1;
  
  while (1){
    
    sigaction(2, displayCurrentMaxPrime(prime));

    if (isPrime(j)){
      prime = j;
    }

    j++;
  }
}


bool isPrime(int num){

  bool numIsPrime = false;

  if (num < 2){
    return numIsPrime;
  }
  
  for (int i=2; i < num; i++){

    if (num % i == 0){
      return numIsPrime;
    }
  }
  
  numIsPrime = true;
  return isPrime;
}


void displayCurrentMaxPrime(int numToDisplay){

  printf("Current highest prime: %d\n", numToDisplay);

  fflush(stdout);
  printf("Quit? [y/n]? ");
  
  fflush(stdout);
  
  char userChoice;
  scanf("%c", &userChoice);

  if (userChoice == "y" || userChoice == "Y"){
      raise(2);
  }

}
