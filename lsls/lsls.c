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
    
    // print out file sizes
    stat(dp->d_name, &buf);
    printf("%10lld  ", buf.st_size);

    // print out file names
    printf("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}