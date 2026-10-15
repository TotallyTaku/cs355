#include <stdio.h>

int main(int argc, char* argv[]){
  printf("argc: %d \n", argc);

  for (int i=0; i < argc; i++){
    printf("argv value: %s \n", argv[i]);
  }
  printf("\n");

  return 0;
}


