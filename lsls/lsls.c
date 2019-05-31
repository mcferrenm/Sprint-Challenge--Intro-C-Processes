#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void list_dir(const char *name, int indent) {
  DIR *dir;
  struct dirent *dp;
  struct stat buf;

  // Open directory
  if ((dir = opendir(name)) == NULL) {
    return;
  }

  // Repeatly read and print entries  
  while ((dp = readdir(dir)) != NULL) {
    
    // write file information to buffer
    stat(dp->d_name, &buf);

    // check if its a file, directory or something else
    if (S_ISDIR(buf.st_mode)) {
        char path[1024];

        // get path and recursively call lsls
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
          printf("%*s%s\n", indent, "<DIR>  ", dp->d_name);
          continue;
        }

        // Print <DIR> instead of file size
        printf("%*s%s\n", indent, "<DIR>  ", dp->d_name);
        snprintf(path, sizeof(path), "%s/%s", name, dp->d_name);
        list_dir(path, indent + 12);

    } else if (S_ISREG(buf.st_mode)) {

      // print out file sizes
      printf("%10lld  %s\n", buf.st_size, dp->d_name);
    /**
    * @TODO What goes in others?
    */
    } else {
      printf("Something else");
    }
  }

  // Close directory
  closedir(dir);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  list_dir(argv[1], 12);
  return 0;
}