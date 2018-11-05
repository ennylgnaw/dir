#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/dir.h>
#include <errno.h>

void indent(int num_indents){
  for(int i=0; i<num_indents; i++)
    printf("    ");
}

void rprint_dir(char * dir, int dir_num){
  DIR *d;
  d = opendir(dir);
   
  if(!d){
    return;
  }
 
  struct dirent* file = readdir(d);
  while (file) {
    indent(dir_num);
    if( !(strcmp(file->d_name, ".")==0) &&
	!(strcmp(file->d_name, "..")==0)){
      if (file->d_type == DT_DIR){
	printf("Directory: /");
	printf("%s", file->d_name);
	printf("\n");
      	rprint_dir(file->d_name, dir_num+1);
      }

      else{
	printf("Regular File: %s", file->d_name);
	struct stat* fmeta = malloc(sizeof(struct stat));
	stat(file->d_name, fmeta);
	printf("-----------%lld\n", fmeta->st_size);
	
      }
    }
    
    file = readdir(d);
  }

}

void print_dir(char * d){
  rprint_dir(d,0);
}

int main(int argc, char* argv[]){
  if(argc > 1)
    print_dir(argv[1]);
  else{
    char *s = malloc(256);
    printf("Enter a directory\n");
    fgets(s, 256, stdin);
    s[strlen(s)-1] = NULL;
    DIR * d = opendir(s);
    if(!d){
      printf("Bad directory: %s\n", strerror(errno));
      return 1;
    }
    print_dir(s);
  }

  
  return 0;
}
