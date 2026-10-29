---
tags:
  - class
  - Fall2026
class: CS355
creation_date: 2026-10-27
---

# CS355 Terminal Commands

> ALL of this information is available using `man <command>`

## Print working Directory pwd `pwd`
- Prints the current directory you're in

Example usage:

- `pwd` returns new line followed by `~/home/<username>` (default directory aka. **home directory**)

## Change directory cd `cd`
- Changes from current directory to given directory(folder)
*Going up directories means going to previous directories(parents), conversely going down means to go further within the current directory (children)*

Example uses: 

- `cd` or `cd ~` navigates to home folder `~/home/<username>` typically

- `cd /` navigates to root folder (parent of all other folders in the system)

- `cd .` navigates to current directory (since `.` stand for current directory)

- `cd ..` navigates to previous directory (since `..` stand for previous directory)

- `cd ../..` navigates TWO directories up

>Using `/` allows for inputting the next directory in sequence up or down
>

- `cd CCSU/Fall2026/CS355` from the home directory, navigate through CCSU into Fall2026 into CS355 

## Remove rm `rm`
- Removes a file or directory 

Example uses: 
- `rm <filename>` removes a file
- `rm -f <filename>` forcefully removes a file even if its open or being used

- `rm -r <directory>` recursively goes into a directory and deletes itself and all its children 

## Remove Directory rmdir `rmdir`
- Removes a directory *IF* it is empty

Example uses: 

- `rmdir <directory>` will remove the directory if empty


## List Directory ls `ls`
- Lists the content in a directory

Example use: 

- `l` or `ls` lists content in the directory like `<file name>` `<filename>` `<directory>/`

- `ls -a` lists ALL the content in a directory including hidden files 

- `ls -i` lists all the files and contents in the current directory with a leading inode number corresponding to the file/directory like `256 <filename> 512<directory/ 1988<filename>`


## Move(rename) mv `mv`
- **Renames** SOURCE to DESTINATION or **moves** SOURCE to DESTINATION

Example uses: 

- `mv <filename> <new_filename>` renames file to new file name

- `mv <filename> <directory>` moves file with filename into directory

- `mv <filename> <filename2> <directory>/` moves multiple files into the directory
	- specify entire path of directory

- `mv <directory> <directory2>/` moves a directory into directory2

- `mv <directory1> <directory2> <directory3>/` moves directory 1 and 2 into directory 3
	- Specify entire path of directory 3

- `mv -t <directory> <filename>` move file into directory writing the directory first
	- Can be used to move multiple files or directories as well

## Copy cp `cp`
- Copies SOURCE to DESTINATION

Example uses: 

- Same functionality as [[#CS355 Terminal Commands#Move(rename) mv `mv`|mv notes]]

## Create files/change timestamps touch `touch`

- Changes timestamps of files though **mostly** used to create files

Example uses: 

- `touch <filename>` creates a new file in the current directory with name filename

## Concatenate and print files cat `cat`

- Concatenates multiple files and prints them to standard output typically the Terminal

Example uses: 

- `cat <filename>` prints the content of a file into the standard output

- `cat <filename> <filename2>` prints the content of filename followed by the content of filename2 into the standard output

- `cat -n <filename>` prints the content of a file with the number of each line prefixed to the content of that line 
