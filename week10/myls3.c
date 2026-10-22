#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int do_ls(char* directory){
  
  DIR* directoryStream;        // DIRECTORY POINTER connected to the directory's stream of directories/files  
  struct dirent* currentEntry; // struct from which we can extract data of the current Entry in the directory/file (filename = d_name)


  // exit if opening directory fails 
  if ((directoryStream  = opendir(directory)) == NULL){
    perror("Failed to open directory");
      exit(EXIT_FAILURE);  
    }


  // read all the entries in the current Stream
  while ((currentEntry = readdir(directoryStream)) != NULL){

    // if the current directory has a hidden file, skip over it 
    if (currentEntry->d_name[0] == '.'){
      continue;
    } else {
        
      struct stat sb;
      // exit if opening sb fails
      if ((stat(directory, &sb)) == -1){
        perror("lstat");
        exit(EXIT_FAILURE);
      }
      
      char mode_str[11] = "----------";
      struct passwd* pwd;
    
      // ADD CODE HERE TO MODIFY mode_str
      // CODE HERE



      pwd = getpwuid(sb.st_uid);

      //printf("Last modified: %s \n", ctime(&sb.st_mtim.tv_sec));
      char* last_mod = ctime(&sb.st_mtim.tv_sec);
      //last_mod[sizeof(last_mod)-1] = 'L';

      printf("%s %ld %s %s %ld %s %s\n", mode_str, sb.st_nlink, pwd->pw_name, getgrgid(sb.st_uid)->gr_name, sb.st_size, last_mod, currentEntry->d_name);
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
