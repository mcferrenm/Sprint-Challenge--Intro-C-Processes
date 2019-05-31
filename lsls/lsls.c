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
  int i;
  DIR *dir;
  struct dirent *dp;
  struct stat buf;

  // Parse command line

  // Open directory
  if ((dir = opendir(argv[1])) == NULL) {
    perror ("Cannot open .");
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