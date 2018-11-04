#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/dir.h>

void indent(int num_indents){
  for(int i=0; i<num_indents; i++)
    printf("    ");
}

void print_dir(char * dir, int dir_num){
  DIR *d;
  d = opendir(dir);
   
  if(!d){
    return;
  }
 
  struct dirent* file = readdir(d);
  while (file) {
    indent(dir_num);
    if( !strcmp(file->d_name, ".")==0 &&
	!strcmp(file->d_name, "..")==0){
      if (file->d_type == DT_DIR){
	printf("/");
	printf("%s", file->d_name);
	printf("\n");
      	print_dir(file->d_name, dir_num+1);
      }

      else{
	printf("%s", file->d_name);
	struct stat* fmeta = malloc(sizeof(struct stat));
	stat(file->d_name, fmeta);
	printf("-----------%d\n", fmeta->st_size);
	
      }
    }
    
    file = readdir(d);
  }

}

int main(int c, char*){
  print_dir("./", 0);
  
  return 0;
}
