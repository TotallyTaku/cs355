#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h> // used to generate error codes


int main(int argc, char *argv[])
{

  // this program only works if its given 3 arguments 
  if (argc != 3){
    printf("Enter correct number of arguments (3)\n");
    return 1;
  }

  
  // Open or create a file if it doesnt exist
  // Append to it O_APPEND if it does exist
  // If creating the file, Allow user to read and write S_IRUSR, S_IWUSR
  int fd = open(argv[1],O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);

  // Below is how we can open a file with permissions based on a binary value for 0_0bOwner_0bGroup_0bEveryone
  // Look at obsidian CS355 File permissions in Linux
  //int fd = open(argv[1], O_CREAT| O_RDWR| O_APPEND, 0666);

  // check if opening failed or not 
  if (fd == -1){
    perror("open failed");
    return 1;
  }

  // Open old file from which to read content in READ only mode  
  int old_fd = open(argv[2], O_RDONLY);
  
  // check if opening failed 
  if (old_fd == -1){
    perror("old file open failed");
    return 1;
  }

  // define a buffer which is an array content of 1000 empty char 
  char content[1000] = {0};

  // read the content from old file and store them in content 
  int bytes = read(old_fd, content, sizeof(content));


  // Alternatively we can use a small buffer and read the file using a while loop
  // char buffer[10] = {0};
  // while (read(old_fd, buffer, sizeof(buffer) > 0){
  //  printf("%s", buffer);
  // }

  // check if reading failed, if it passed, print what was read 
  if (bytes > 0){
  printf("Read: %s\n", content);  
  }

  // close old file 
  close(old_fd);


  // write to the new file all the content we read from old file 
  if (write(fd, content, sizeof(content)) == -1){
    perror("write to new file failed");
  }


  printf("Written to new file: %s \n", content);
  // close new file 

  close(fd);
  return 0;
}

