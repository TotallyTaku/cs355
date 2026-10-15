#include <stdio.h>

int main(int argc, char *argv[])
{
  int x = 1, y = 2, z[10];
  int* ip;            /* ip is a pointer to an integer*/ 

  ip = &x;            /* ip points to x*/
  y = *ip;            /* y is now 1*/
  *ip = 0;            /* x is now 0*/
  ip = &z[0];         /*ip now points to z[0] */

  return EXIT_SUCCESS;
}

