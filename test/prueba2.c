#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sched.h>

void main(){
  int i;
  int pid;
  int a;

  for (i=0;i<10;i++){
    if((pid=fork())==-1){
	    printf("Error al hacer el fork\n");
	      exit(1);
    }
    if(pid==0){
	    if(execl("pagos",NULL)==-1){
	      printf("Error al ejecutar\n");
	      exit(1);
	    }
    }
 
  }
  
  int j;
  for(j=0;j<10;j++){
    a=2;
  }
}

