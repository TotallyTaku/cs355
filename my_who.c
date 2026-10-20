#include <stdio.h>
#include <fcntl.h>
#include <utmp.h>
#include <unistd.h>


int main(int argc, char *argv[])
{

  int EXIT_SUCCESS = 0;


  struct utmp current_record;

  int utmp_id = open("/var/run/utmp", O_RDONLY);

  while(read(utmp_id, &current_record, sizeof(current_record)) == sizeof(current_record)){
    
    printf("%s ", current_record.ut_user);
    printf("%s ", current_record.ut_line);
    //printf("%d \n", current_record.ut_session);
    printf("%d \n", current_record.ut_tv.tv_sec); // returns the number of seconds since EPIC ~ 1970
    long time = current_record.ut_tv.tv_sec;
    time = time % (60*60*24*365);
    printf("%ld \n", time);

  }

  //printf("user: %s \n", current_record.ut_host);

  return EXIT_SUCCESS;
}


