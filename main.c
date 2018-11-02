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
  d = opendir("testdir");
  struct dirent* file = readdir(d);
  file = readdir(d);
  file = readdir(d);
  printf("%c\n", file->d_name[0]);
  printf("%c", file->d_name[1]);
  //printf("%c", file->d_name[2]);
  //printf("%c", file->d_name[3]);
  return 0;
}
