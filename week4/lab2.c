#include <stdio.h>



int main(int argc, char *argv[])
{
  int EXIT_SUCCESS = 0;

  // iterate through the argv count skipping over the file name
  for (int i=1; i < argc; i++){
      
    char message[100] = {};
    char* current_string = argv[i]; // grab the current string argument
      
    // iterate through the string to get individual characters
    for(int j=0; j < sizeof(current_string); j++){
      
      char current_char = current_string[j]; // convert the character to string
      int ascii_value = (int)current_char;
    
      // Change from Upper case to lower case by changing ascii_value + 32
      
      if (ascii_value >=97 && ascii_value <= 122){
        current_char = (char)ascii_value;
      }else if(ascii_value >= 65 && ascii_value <= 90){
        ascii_value = ascii_value + 32;
      } else {break;}
      
        // the current_char should be lowercase
        current_char = (char)ascii_value;
      
      
        message[j] = current_char;
    
        int k = 0;
        while (message[k]!= '\0'){
          printf("%c",message[k]);
          k++;
        }
        printf("\n");
    }
 //   printf("%s\n", message);
    }
    

  return EXIT_SUCCESS;
}
