/*  main.c  - main */

#include <xinu.h>
void sndChar(char);

process	main(void){	
  resume(create(produser, 1024, 20, "produser",0));
  resume(create(consumer, 1024, 20, "konsumen",0));
  return OK;
}

void produser(void){
  int32 i;
  for  (i=1; i<=1001; i++){
    n++;
  }
}

void consumer(void){
  int32 i;
  for (i=1; i<1001; i++){
    printf("Nilai dari n adalah %d\n", n);
  }
}
