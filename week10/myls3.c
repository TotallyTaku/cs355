#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

/** modifies the given char array by checking the enabled modes of the current
file / by facilitating struct stat* sb
*/
void modify_mode_string(struct stat *sb, char mode_str[]) {

  if (S_ISDIR(sb->st_mode)) {
    mode_str[0] = 'd';
  }

  mode_str[1] = (sb->st_mode & S_IRUSR) ? 'r' : '-';
  mode_str[2] = (sb->st_mode & S_IWUSR) ? 'w' : '-';
  mode_str[3] = (sb->st_mode & S_IXUSR) ? 'x' : '-';

  mode_str[4] = (sb->st_mode & S_IRGRP) ? 'r' : '-';
  mode_str[5] = (sb->st_mode & S_IWGRP) ? 'w' : '-';
  mode_str[6] = (sb->st_mode & S_IXGRP) ? 'x' : '-';

  mode_str[7] = (sb->st_mode & S_IROTH) ? 'r' : '-';
  mode_str[8] = (sb->st_mode & S_IWOTH) ? 'w' : '-';
  mode_str[9] = (sb->st_mode & S_IXOTH) ? 'x' : '-';
}

int do_ls(char *directory) {

  DIR *directoryStream; // DIRECTORY POINTER connected to the directory's stream
                        // of directories/files
  struct dirent
      *currentEntry; // struct from which we can extract data of the current
                     // Entry in the directory/file (filename = d_name)

  // exit if opening directory fails
  if ((directoryStream = opendir(directory)) == NULL) {
    perror("Failed to open directory");
    exit(EXIT_FAILURE);
  }

  // read all the entries in the current Stream
  while ((currentEntry = readdir(directoryStream)) != NULL) {

    // if the current directory has a hidden file, skip over it
    if (currentEntry->d_name[0] == '.') {
      continue;
    } else {

      struct stat sb;
      // exit if opening sb fails
      if ((stat(currentEntry->d_name, &sb)) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
      }

      struct passwd *pwd; // create pointer to instance of struct passwd

      char mode_str[11] = "----------";  // string to show modes of the files
      modify_mode_string(&sb, mode_str); // modify string

      pwd = getpwuid(sb.st_uid); // save instantiation info into pwd

      struct group *grp =
          getgrgid(sb.st_gid); // create pointer and save pointer to
                               // instantiation of group

      char *time_str =
          ctime(&sb.st_mtime); // create string to show last modified time in
                               // human readable string
      char last_mod[13];       // length of string to have max important info

      // the string's relevant info starts in index 5 and above so I skip to it
      // You can find this out by parsing through time_str to see each char
      for (int i = 0; i < 12; i++) {
        last_mod[i] = time_str[i + 4];
      }

      last_mod[12] = '\0'; // terminate string
      printf("%s %ld %s %s %ld %s %s\n", mode_str, (long)sb.st_nlink,
             pwd->pw_name, getgrgid(sb.st_uid)->gr_name, (long)sb.st_size,
             last_mod, currentEntry->d_name);
    }
  }
  closedir(directoryStream);

  return 0;
}

int main(int argc, char *argv[]) {
  char *currentDirectory; // String name for current directory

  // define default name for currentDirectory if no flags or direcroties given
  // (./my_ls = ./my_ls .)
  if (argc == 1) {
    currentDirectory = ".";
    do_ls(currentDirectory);
  } else {

    // if more than one argc given (./my_ls + <something>)
    for (int i = 1; i < argc; i++) {

      // if this current argument is NOT a flag (like -a, -l, etc.)
      if (argv[i][0] != '-') {
        currentDirectory = argv[i];
        do_ls(currentDirectory);
      }
    }
  }
  return 0;
}
