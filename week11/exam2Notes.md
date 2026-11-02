

## Errno
- What is errno, What is it for? How is it used? Provide specific examples

**errno** provided by the library `<errno.h>`

errno is the number value returned by a function to notify an error happened during the process.
It is simply an integer value to check after a function is called to know if the function failed or not.
All of our lower level functions like read(), write(), open(), close() return an errno 

## Perror 
- What is perror, What is it for? What is it used for? Provide specific examples 

**perror** provided by the library `<errno.h>`

perror is a function used to provide human readable information(string) in regard to the error reported from a function's errno.

Say you call a function, if it fails it will return an int if its an int function AND set errno to a number based on the reason for its failure. With perror() you can print the reason the function failed based on the errno set by the function. 


For example we can call open() on a directory and if it fails it'll return -1. 
- We can do something like if (open() == -1) perror("Open failed");
- Because open() sets errno to 2 when an invalid directory is given.
  - we know that the file opening failed and thus can provide more information inside of perror like perror("Open failed");
  - This will print out the string inside of perror() followed by the information provided by the actual errno
  - output: Open failed: No such file or directory 

So we check if the function failed with if (open() == -1) and if it does we know it will set an errno so we check that after

With this we can let the user know that the open function failed open(). 
And then we can let it know WHY it failed (perror() writes this part for us)



