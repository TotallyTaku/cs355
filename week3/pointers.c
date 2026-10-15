#include <stdio.h>




int main(){

  int value = 5;        // value is 5
  int* pvalue = &value; // pvalue has the address of value
  

  printf("Original value: %d\n", value);
  //printf("Address of the variable value: %p \n", (void*)pvalue);

  printf("Value through pointer: %d\n", *pvalue);

  *pvalue = 7;        

  printf("Changed value: %d\n", value);
  printf("Changed value through pointer: %d\n", *pvalue);
  return 0;

}
