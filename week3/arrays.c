#include <stdio.h>


void pass_by_value(int*);

int main(){
  int my_array[5] = {10, 20, 30, 40, 50};
  
  printf("my_array = {");

  for (unsigned int i=0; i < sizeof(my_array)/4; i++){
    if (i == sizeof(my_array)/4 - 1){
      printf("%d", my_array[i]);
    }else {
      printf("%d,", my_array[i]);
    }
  }
  printf("}\n");

  // prints the first value of the array
  printf("First element of the array through index: %d\n", my_array[0]);
  printf("First element of the array through dereferencing: %d\n", *my_array);
  

  //Modifies an arrray value through index
  printf("Modifying first element of the array and printing through index: %d+10 = %d\n", my_array[0], my_array[0]+10);

  //Modifies an array value through dereferencing
  printf("Modifying first element of array through dereferencing: %d+20 = %d\n", *my_array, *my_array + 20);

  // Moving throgh array by the pointer
  printf("Traversed from address of first index to third index through pointer: %d\n", *(my_array+2)); 

  int temp = 70;
  pass_by_value(&temp);

  return 0;
}

void pass_by_value(int *v){
    printf("The value of v is: %d\n", *v);
    *v = *v +1; // increase the value of v
    printf("The increased value of v is: %d\n", *v);
}



