#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * does the functionality of what typical ls would do in the terminal
 * @args directory the name of the directory to perform ls upon
 * @return 0 on success and -1 on error
 */
int do_ls(char *directory) {

  DIR *directoryStream; // DIRECTORY POINTER connected to the directory's stream
                        // of directories/files
  struct dirent
      *currentEntry; // struct from which we can extract data of the current
                     // Entry in the directory/file (filename = d_name)

  // if we fail to open the directoryStream connected to directory
  if ((directoryStream = opendir(directory)) == NULL) {
    perror(directory);
    return -1; // error out
  }

  // while loop to read all the entries in the current Stream

  unsigned int longestName =
      0;                  // Holds the # of characters for the largest filename
  unsigned int count = 0; // count the number of file names in the directory

  // First pass used to : count files and find the longest file name
  while ((currentEntry = readdir(directoryStream)) != NULL) {

    // if the current directory has a hidden file, skip over it
    if (currentEntry->d_name[0] == '.') {
      continue;
    }

    unsigned int length = 0;

    // store length of current file name
    while (currentEntry->d_name[length] != '\0') {
      length++;
    }

    // if current file has the longest name save its # of characters
    if (length > longestName) {
      longestName = length;
    }

    count++; // count the # of files read through
  }

  if (count == 0) {
    closedir(directoryStream);
    return 0;
  }

  // Allocate an array of pointers to filenames
  char **names = malloc(count * sizeof *names);

  // check if malloc memory allocation failed
  if (names == NULL) {
    perror("malloc");
    closedir(directoryStream);
    return -1;
  }

  // go back to beginning of same directory
  rewinddir(directoryStream);

  unsigned int stored = 0; //  saves the # of stored filenames in the directory

  // Second pass: make a separate copy of each filename
  while (stored < count && (currentEntry = readdir(directoryStream)) != NULL) {

    if (currentEntry->d_name[0] == '.') {
      continue;
    }

    unsigned int length = 0;
    while (currentEntry->d_name[length] != '\0') {
      length++;
    }

    // Allocate memory for this filename including the terminating '\0'
    names[stored] = malloc(length + 1);

    // if malloc fails
    // free the filenames already allocated and the array "names"
    if (names[stored] == NULL) {
      perror("malloc");

      for (unsigned int i = 0; i < stored; i++) {
        free(names[i]);
      }
      free(names);
      closedir(directoryStream);
      return -1;
    }

    // Copy this filename, including '\0' into its allocated memory
    for (unsigned int i = 0; i <= length; i++) {
      names[stored][i] = currentEntry->d_name[i];
    }

    if (length > longestName) {
      longestName = length;
    }

    stored++; // increase # of stored filenames
  }

  int result = 0;

  if (closedir(directoryStream) == -1) {
    perror("closedir");
    result = -1;
  }

  count = stored; // use the number of actually stored filenames inside of array
                  // "names"

  // at this POINT WE KNOW THE WIDTH OF EACH OF OUR ROWS
  struct winsize wbuf;
  ioctl(0, TIOCGWINSZ, &wbuf);

  unsigned int terminalWidth = wbuf.ws_col;

  unsigned int columnWidth = longestName + 2;
  unsigned int columns = terminalWidth / columnWidth;

  if (columns == 0) {
    columns = 1;
  }

  unsigned int rows = (count + columns - 1) / columns;

  // print each row using the filenames
  for (unsigned int row = 0; row < rows; row++) {
    for (unsigned int col = 0; col < columns; col++) {

      unsigned int index = row + col * rows;

      if (index >= count) {
        break;
      }

      printf("%s", names[index]);

      if (index + rows < count) {
        unsigned int length = 0;

        while (names[index][length] != '\0') {
          length++;
        }

        printf("%*s", (int)(columnWidth - length), "");
      }
    }
    printf("\n");
  }
  // free each filename and then the array "names" holding the pointers
  for (unsigned int i = 0; i < count; i++) {
    free(names[i]);
  }

  free(names);
  return result;
}

int main(int argc, char *argv[]) {

  char *currentDirectory; // String name for current directory
  int result = 0;

  // define default name for currentDirectory if no flags or direcroties given
  // (./my_ls = ./my_ls .)
  if (argc == 1) {
    currentDirectory = ".";
    if (do_ls(currentDirectory) == -1) {
      result = -1;
    }
  } else {

    // if more than one argc given (./my_ls + <something>)
    for (int i = 1; i < argc; i++) {

      // if this current argument is NOT a flag (like -a, -l, etc.)
      if (argv[i][0] != '-') {
        currentDirectory = argv[i];
        if (do_ls(currentDirectory) == -1) {
          result = 1;
        }
      }
    }
  }
  return result;
}
