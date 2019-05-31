#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Initialize variables
  DIR *dir;
  struct dirent *dp;
  struct stat buf;

  // Open directory
  if ((dir = opendir(argv[1])) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit (1);
  }

  // Repeatly read and print entries  
  while ((dp = readdir(dir)) != NULL) {
    
    // write file information to buffer
    stat(dp->d_name, &buf);

    // check if its a file, directory or something else
    if (S_ISREG(buf.st_mode)) {

      // print out file sizes
      printf("%10lld  ", buf.st_size);

    } else if (S_ISDIR(buf.st_mode)) {
      
      // Print <DIR> instead of file size
      printf("%12s", "<DIR>  ");
      
    /**
    * @TODO What goes in others?
    */
    } else {
      printf("Something else");
    }

    // print out file names
    printf("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}