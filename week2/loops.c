#include <stdio.h>


int main(){

  int sum = 0;
  int num = 0;

//  while (num <= 100){ 
//    sum = sum + num;
//    num ++;
//  }

  for (num=1; num <= 100; num = num+2){
    sum = sum + num;
  }

  printf("sum total: %d\n", sum);

  return 0;

}
