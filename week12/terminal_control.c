#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  char* f_name = "/dev/tty";
  char buff[30] = "Hello Tuesday!\n";

  int fd = open(f_name, O_WRONLY);

  write(fd, buff, 16);

  close(fd);
  return EXIT_SUCCESS;
}
