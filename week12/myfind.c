#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>


int do_ls(char* directory){

  DIR* directoryStream;
  struct dirent* currentEntry;

  directoryStream = opendir(directory);

  if (directoryStream == NULL) {
    perror("opendir() failed");
    return -1;
  }

  printf("%s : \n", directory);

  // use stream to read from current directory
  while((currentEntry = readdir(directoryStream))!= NULL){
    
    // if hidden file ignore it 
    if (currentEntry->d_name[0] == '.'){
      continue;
    } else{
     printf("%s ", currentEntry->d_name);
    }
  }
  printf("\n");
  
  if((closedir(directoryStream)) == -1){
    perror("closedir() error");
    return -1;
  }

  return 0;
}




int main(int argc, char *argv[])
{

  char* currentDirectory;


  if (argc == 1){
    currentDirectory = ".";
    do_ls(currentDirectory);
  } else {

    for (int i=1; i < argc; i++){

      currentDirectory = argv[i];
      do_ls(currentDirectory);
    }
  }
  return EXIT_SUCCESS;
}
