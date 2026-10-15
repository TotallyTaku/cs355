#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/ioctl.h>


// this function is not used in the actual code
// I was using it to figure out which varible gave me the width of the terminal
// wbuf.ws_col does.
void print_screen_dimensions(){

  struct winsize wbuf;
  if (ioctl(0, TIOCGWINSZ, &wbuf) != -1){
    printf("%d rows x %d cols\n", wbuf.ws_row, wbuf.ws_col);
    printf("%d wide x %d tall\n", wbuf.ws_xpixel, wbuf.ws_ypixel);
  }
}

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
      
      // while loop to read all the entries in the current Stream
    
      unsigned int maxCharacterSizeCounter = 0;

      while ((currentEntry = readdir(directoryStream)) != NULL){

        // if the current directory has a hidden file, skip over it 
        if (currentEntry->d_name[0] == '.'){
        continue;
        } else {
          unsigned int i=0;
          unsigned int currentMaxCharacterSizeCounter = 0;
          
          while (currentEntry->d_name[i] != '\0'){
            currentMaxCharacterSizeCounter++;
            i++;
          }

          printf("max char counter: %d\ncurrent max char counter: %d\n", maxCharacterSizeCounter, currentMaxCharacterSizeCounter);

          if (currentMaxCharacterSizeCounter > maxCharacterSizeCounter){
            maxCharacterSizeCounter = currentMaxCharacterSizeCounter;
          }

        }
      }
      
      closedir(directoryStream);
      directoryStream = opendir(directory);
      
      while ((currentEntry = readdir(directoryStream)) != NULL){
        unsigned int currentMaxCharacterSizeCounter = 0;
        if (currentEntry->d_name[0] == '.'){
        continue;
        } else{
          
          unsigned int i= 0;
          while (currentEntry->d_name[i] != '\0'){
            
            currentMaxCharacterSizeCounter++;
            i++;
          }
          // at this POINT WE KNOW THE WIDTH OF EACH OF OUR ROWS 
          
          struct winsize wbuf;
          ioctl(0, TIOCGWINSZ, &wbuf);
          unsigned int columnSpace = wbuf.ws_col;
  

          unsigned int numFilesPerRow = columnSpace / maxCharacterSizeCounter;
          for (int j=0; j < numFilesPerRow; j++){
            printf("%s%*s", currentEntry->d_name, maxCharacterSizeCounter - currentMaxCharacterSizeCounter + 1, " ");
          }
          printf("\n");
        }
      }
      printf("\n"); // new line after printing the name of all the files and directories inside current directory 
    } 
    
    printf("\n"); // new line to have a space in between directories 
    
    // check if we were unable to close the stream of data in current directory 
    if ((closedir(directoryStream)) == -1){
      printf("Issue closing directoryStream");
      return -1;
    }
}


int main(int argc, char *argv[])
{

  //print_screen_dimensions();

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
