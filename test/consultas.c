#include <stdio.h>
#include <time.h>

void main(){

  clock_t start = clock();
  pid_t pid = getpid();
  int i;

  printf("\n");
  printf("El PID es: %d\n",pid);

  for (i=0; i<8e8; i++){
  }
  clock_t end = clock();

  double tiempo = end-start;
  double elapsed = tiempo/CLOCKS_PER_SEC;

  printf("Tiempo ocupado: %.3f segundos\n",elapsed);

}
