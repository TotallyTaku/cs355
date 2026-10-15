#include <utmp.h>           // utmp header for utmp structure and UTMP_FILE location
#include <fcntl.h>          // file control library for open function
#include <unistd.h>         // library for read and close functions
#include <stdio.h>
#define SHOWHOST 1          // enable host display (1 = on, 0 = off)

/*
 *  show info()
 *   displays contents of the utmp struct in human readable form
 *   *note* these sizes should not be hardwired
 */
void show_info(struct utmp *utbufp) // Function takes a pointer to utmp structure as input
{
    printf("%-8.8s", utbufp->ut_user);      // Print username, limited to 8 characters, left-justified
                                            // meaning, add padding to the right-ahdn side of the string
    printf(" ");                            // Add a space between fields
    printf("%-8.8s", utbufp->ut_line);      // Print terminal line (e.g., tty1), limited to 8 characters
    printf(" ");                              
                        
#ifdef SHOWHOST
    //printf("(%s)", utbufp->ut_host);        // Print hostname in parentheses if SHOWHOST is defined
#endif
  printf("%d ", utbufp->ut_pid);
    printf("%d ", utbufp->ut_tv.tv_sec);
    printf("%d",utbufp->ut_session);
    printf("\n");                           // Move to a new line after each record
}

int main()
{
    struct utmp current_record;          // a utmp structure to store each record read from file
    int utmpfd;                          // file descriptor for the utmp file
                                         // This also acts as an pointer to the file's location,
                                         // which we will learn in a future session
    int reclen = sizeof(current_record); // Calculate the size of the utmp structure for reading

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) { // Open utmp file in read-only mode; fopen returns -1 if failure happens
        perror(UTMP_FILE);              // Print error message if file opening fails, using UTMP_FILE name
        return 1;                       // Return 1 to indicate error and exit
    }

    while (read(utmpfd, &current_record, reclen) == reclen) { // Read utmp records until end or error
        show_info(&current_record);    
    }

    close(utmpfd);                      // Close the utmp file descriptor to free resources
    return 0;                           // Return 0 to indicate successful execution of the code
}
