#include <stdio.h>
#include <time.h>

void main(){

  clock_t start = clock();
  pid_t pid = getpid();
  int i;
  
  if(pid!=-1){
    char command[1024];
    snprintf(command,sizeof(command),"chrt -p %d",pid);
    system(command);
  }
  for (i=0; i<7e8; i++){
  }
  clock_t end = clock();

  double tiempo = end-start;
  double elapsed = tiempo/CLOCKS_PER_SEC;

  printf("Tiempo ocupado: %.3f segundos\n",elapsed);

}
