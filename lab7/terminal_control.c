#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{

  char* f_name = "/dev/tty3";
  char buff[30] = "Hello Tuesday!\n";

  int fd = open(f_name, O_WRONLY);
  if (fd == -1){
    //printf("Error in opening the file!\n");
    //printf("errno: %d\n", errno);
    
    
    // this works but not very practical.
    //switch (errno) {
    //  case 1: 
    //    printf("Operation not allowed\n");
    //    break;
    //  
    //  case 2: 
    //    printf("No such file or directory\n");
    //    break;

    //  case 3:
    //    printf("No such process\n");
    //    break;

    //  case 4: 
    //    printf("Interrupted system call\n");
    //    break;

    //  case 5: 
    //    printf("Input/output error\n");
    //    break;

    //  case 13:
    //    printf("Permission denied\n");
    //    break;
    //}

    // this is good if you want to save the string but there is a better way to do it 
    //printf("%s\n", strerror(errno));

    perror("Error in open()");

    return -1;
  }

  write(fd, buff, 16);

  close(fd);
  return EXIT_SUCCESS;
}
