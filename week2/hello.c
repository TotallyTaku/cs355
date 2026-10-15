#include <stdio.h>

int main(){

  //char my_char = 'K';
  //int my_int = 7;
  //float my_float = 4.5;
  //double my_double = 0.3333333;

  //printf("my_char is: %c\n", my_char);     // prints a character as a char (alternatively can use %d to print its ascii value)
  //printf("my_int is: %d\n", my_int);       // prints an integer
  //printf("my_float is: %.2f\n", my_float); // prints a floating-point character with upto 2 digits of precision 
  //printf("my_double is: %f\n", my_double); // prints a double without a specified max number of digits of precision



  // lets say we try to have an int but write a float value

  //int my_float = 4.5;
  //printf("my int is: %d\n", my_float); // this will print 4 (truncates)


  //char fL= 'K';
  //char sL = 'e';
  //char tL = 'm';
  //char fourth_L = 'u';
  //char fifth_L= 'e';
  //char sixth_L = 'l';

  //printf("%c%c%c%c%c%c\n",fL, sL, tL, fourth_L, fifth_L, sixth_L);


  //int farenheit = 75;
  //float celsius = ((double)farenheit - 32) * 5/9;
  
  //printf("Farenheit temp: %d\n", farenheit);
  //printf("Celsius temp: %f\n", celsius);
  float celsius = 23.0;

  float farenheit = (celsius * 9/5) +32;

  printf("Farenheit temp: %.2f\n", farenheit);


  return 0;

}
