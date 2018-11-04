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

void print_string(char * ar){  
  for(int i=0; ar[i]; i++)
    printf("%c", ar[i]);
  printf("\n");
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
	print_string(file->d_name);
      
	print_dir(file->d_name, dir_num+1);
      }

      else{
	print_string(file->d_name);
      }
    }
    
    file = readdir(d);
  }

}
int main(){
  print_dir("./", 0);
  
  return 0;
}
