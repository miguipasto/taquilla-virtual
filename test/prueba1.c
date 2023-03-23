#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sched.h>

void main(){
  int i;
  int pid;
  int a;

  
    if((pid=fork())==-1){
	    printf("Error al hacer el fork\n");
	      exit(1);
    }
    if(pid==0){
	    if(execl("mantenimiento",NULL)==-1){
	      printf("Error al ejecutar\n");
	      exit(1);
	    }
    }
    if((pid=fork())==-1){
      printf("Error al hacer el fork\n");
      exit(1);
    }
    if(pid==0){
	    if(execl("consultas",NULL)==-1){
              printf("Error al ejecutar\n");
              exit(1);
            }
    }
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
    if((pid=fork())==-1){
      printf("Error al hacer el fork\n");
      exit(1);
    }
    if(pid==0){

	    if(execl("consultas",NULL)==-1){
              printf("Error al ejecutar\n");
              exit(1);
            }
    }
    if((pid=fork())==-1){
      printf("Error al hacer el fork\n");
      exit(1);
    }
    if(pid==0){

	    if(execl("administracion",NULL)==-1){
              printf("Error al ejecutar\n");
              exit(1);
            }
    }
    if((pid=fork())==-1){
      printf("Error al hacer el fork\n");
      exit(1);
    }
    if(pid==0){

	    if(execl("reservas",NULL)==-1){
              printf("Error al ejecutar\n");
              exit(1);
            }
    }
    if((pid=fork())==-1){
      printf("Error al hacer el fork\n");
      exit(1);
    }
    if(pid==0){

	    if(execl("mantenimiento",NULL)==-1){
              printf("Error al ejecutar\n");
              exit(1);
            }
    }

 
  
  
  int j;
  for(j=0;j<10;j++){
    a=2;
  }
}

