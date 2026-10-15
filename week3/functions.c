#include <stdio.h>


//int area_of_square(int);
void area_of_rectangle(int, int, int, int);

int main(){

  area_of_rectangle(10, 8, 4, 3);
  return 0;
}


//return_type function_name(arg_type arg1, arg_type arg2){
//  return return_type;
//}

//int area_of_square(int length){
//
//  int area = length * length;
//
//  return area;
//}

void area_of_rectangle(int length, int height, int sub_length, int sub_height){
  int area = (length * height) - (sub_length * sub_height);
  printf("The area of the rectangle is: %d\n", area);
}
