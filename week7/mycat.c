#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int print_file(char*[]);

int main(int argc, char *argv[])
{

  // Check that we're running the program with appropriate argument count

  if (argc < 2){
perror("Argument count invalid (2-5)\n");
  } else if (argc > 5){
    perror("Argument count invalid (2-5)\n");
  }

    
    char current_char = argv[1][0];
    // Identify whether we have a flag to pass to print_file or not.
    if (current_char == '-') {
      printf("Argv[1] is a FLAG!\n");
    }



  char* arguments[4];

  for (int i=1; i < argc;i++){
    arguments[i-1] = argv[i];
    printf("argument[%d]=%s\n"i-1, arguments[i-1]);
  }

  print_file(arguments);


  return EXIT_SUCCESS;
}


/*Returns 0 if successful and -1 if unsuccessful*/
int print_file(char* contents[]){
  
  // initialize message to be read
  char message[1000] = {0};


  for (int i=1; i < sizeof(contents); i++){
    

    int fd = open(contents[i], O_RDONLY);

    if (fd == -1){
      perror("open failed\n");
      return -1;
    }

    while(read(fd, message, sizeof(message)) > 0){

    }
  }

  // READ ALL TO A MASSIVE MESSAGE BUFFER THEN GO BACK TO IT and modify as needed. 

  // read through the entire given file and print to terminal


  while (read(fd, message, sizeof(message)) > 0){
    printf("%s\n", message);
  }

  close(fd);
  return 0;
}
