#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>

int do_ls(char* directory){
  
  DIR* directoryStream;        // DIRECTORY POINTER connected to the directory's stream of directories/files  
  struct dirent* currentEntry; // struct from which we can extract data of the current Entry in the directory/file (filename = d_name)


  // return if fail to open the directoryStream connected to directory 
  if ((directoryStream  = opendir(directory)) == NULL){
    printf("Failed to open directory\n");
      return -1; // error out 
    }


  // read all the entries in the current Stream
  while ((currentEntry = readdir(directoryStream)) != NULL){

    // if the current directory has a hidden file, skip over it 
    if (currentEntry->d_name[0] == '.'){
      continue;
      } else {
        
      struct stat sb;
      
      if ((stat(directory, &sb)) == -1){
        perror("lstat");
        exit(EXIT_FAILURE);
      }
        
      char mode_str[11] = "----------";
      printf("mode before: %d\n", sb.st_mode);
      printf("masked mode val: %d\n",sb.st_mode & S_IFMT);

      printf("%d LINKS OWNER GROUP FILE_SIZE LAST_MODIFIED %s\n", sb.st_mode,currentEntry->d_name);

      }
  }   
  closedir(directoryStream); 

  return 0;
}


int main(int argc, char *argv[])
{
  char* currentDirectory; //String name for current directory
 
  // define default name for currentDirectory if no flags or direcroties given (./my_ls = ./my_ls .)
  if (argc == 1){
    currentDirectory = ".";
    do_ls(currentDirectory);
  } else{
    
    // if more than one argc given (./my_ls + <something>)
    for (int i=1; i < argc; i++){
      
      // if this current argument is NOT a flag (like -a, -l, etc.)
      if (argv[i][0] != '-'){
        currentDirectory = argv[i];
        do_ls(currentDirectory);
      }

    }
  }
 return 0;
}
