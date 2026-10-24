#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Check that we're running the program with appropriate argument count

  if (argc < 2) {
    printf("Argument count invalid (2-5)\n");
    return 1;
  } else if (argc > 5) {
    printf("Argument count invalid (2-5)\n");
    return 1;
  }

  // variables for flag -e, -n, -s,
  int displayDollar = 0;
  int showLineNumber = 0;
  int squeezeLines = 0;

  int startOfLine = 1; // defines if we're at the start of a line we're reading
  int lineNumber = 1;  // displays current line number when -n is inabled

  // fd for open, read, close
  int fd;
  char current_char;  // iterate character by character
  int hasContent = 0; // check to see if a line has content before printing

  for (int i = 1; i < argc; i++) {

    // check if argv have any of the flags as any argv
    if (argv[i][0] == '-') {

      for (int j = 1; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'e')
          displayDollar = 1;
        else if (argv[i][j] == 'n')
          showLineNumber = 1;
        else if (argv[i][j] == 's')
          squeezeLines = 1;
        else {
          printf("Invalid flag\n");
          return 1;
        }
      }
    }
  }

  // open each file
  for (int i = 1; i < argc; i++) {

    if (argv[i][0] == '-') {
      continue;
    }

    fd = open(argv[i], O_RDONLY);

    if (fd == -1) {
      printf("Could not open file: %s", argv[i]);
      continue;
    }

    // read one character at a time
    while (read(fd, &current_char, 1) > 0) {

      // if character is new line
      if (current_char == '\n') {
        // empty line gets skipped with -s
        if (squeezeLines && !hasContent) {
          startOfLine = 1;
          continue;
        }
        // if line number is enabled print number
        if (startOfLine && showLineNumber) {
          printf("%d ", lineNumber);
        }
        // display dollar sign
        if (displayDollar) {
          printf("$");
        }
        // new line and go to the next line
        printf("\n");

        lineNumber++;
        startOfLine = 1;
        hasContent = 0;
      } else {
        // if character is NOT new line
        // if character is not tab or space it has content
        if (current_char != ' ' && current_char != '\t' &&
            current_char != '\r') {
          hasContent = 1;
        }

        // if it has content and we're at start of line print the number of the
        // line we're in
        if (startOfLine) {
          if (showLineNumber) {
            printf("%d ", lineNumber);
          }
          startOfLine = 0;
        }
        // print character
        printf("%c", current_char);
      }
    }
    close(fd);
  }

  if (displayDollar && !startOfLine) {
    printf("$");
  }
  return 0;
}
