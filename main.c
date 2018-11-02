#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(){
  //  struct stat *file = malloc(sizeof(struct stat));
  //  stat("./", file);
  DIR *d;
  d = opendir("./");
  struct dirent* file = readdir(d);
  while (file) {
    if (file->d_type == DT_DIR)
      printf("dir: ");
    for (int i = 0; file->d_name[i]; i++)
      printf("%c", file->d_name[i]);
    printf("\n");
    file = readdir(d);
  }
  //printf("%c", file->d_name[2]);
  //printf("%c", file->d_name[3]);
  return 0;
}
