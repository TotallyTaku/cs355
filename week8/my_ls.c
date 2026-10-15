#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>


/*
 * does the functionality of what typical ls would do in the terminal
 * @args directory the name of the directory to perform ls upon
 * @return 0 on success and -1 on error
*/
int do_ls(char* directory){

  DIR* directoryStream;        // DIRECTORY POINTER connected to the directory's stream of directories/files  
  struct dirent* currentEntry; // struct from which we can extract data of the current Entry in the directory/file (filename = d_name)

  // if we fail to open the directoryStream connected to directory 
  if ((directoryStream  = opendir(directory)) == NULL){
      printf("Failed to open directory\n");
      return -1; // error out 
    } else {
      
      printf("%s : \n", directory); // print the directory name + : so that each directory is printed as 
                                      //<directoryName> :
                                      //<files in directory>
     
      // while loop to read all the entries in the current Stream
      while ((currentEntry = readdir(directoryStream)) != NULL){

        // if the current directory has a hidden file, skip over it 
        if (currentEntry->d_name[0] == '.'){
        continue;
        } else {
        printf("%s ", currentEntry->d_name); // print current name of the entry could be a file name or directory name 
        }
      }
      printf("\n"); // new line after printing the name of all the files and directories inside current directory 
    }
    
    printf("\n"); // new line to have a space in between directories such that 
                  //<directory 1> :
                  //<files and directories> 
                  //
                  //<directory 2> 
    
    // check if we were unable to close the stream of data in current directory 
    if ((closedir(directoryStream)) == -1){
      printf("Issue closing directoryStream");
      return -1;
    }
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

