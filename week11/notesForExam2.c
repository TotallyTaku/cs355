#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>


void open_example(){
  
  // try to open a file that doesn't exist 
  int fd = open("test.txt", O_APPEND);
  
  // we check if fd = -1 which means open() failed 
  if (fd == -1){
    perror("Open failed"); // since it failed we let the user know and perror specifies what specfically failed 
    // You can terminate the program here or deal with the error in some way shape or form.
  }
} 



void myCp_example(char* source, char* destination){

  // Open source as read only O_RDONLY flag
  // Open destination with O_CREAT/O_APPEND whatever you want to do with destination file
  // 


}

int main(int argc, char *argv[])
{
  open_example();


  return EXIT_SUCCESS;
}
