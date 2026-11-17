#include <stdio.h>
#include <unistd.h>
#include <signal.h>



int  main(){

  for (int i=0; i < 20; i++){

    signal(2,SIG_DFL);// when the program sees CTRL C which is the interrupt signal, it will execute
    // the default behavior of the interrupt signal (it will interrupt the program)
    
    //signal(2, SIG_IGN); // when the program sees CTRL C it ignores it and continues executing

    printf("Hello Darkness My Old Friend\n");
    sleep(1);
  }

  return 0;
}

