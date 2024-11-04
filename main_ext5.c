#include <xinu.h>

void producer(void);
void consumer(void);

sid32 s1, s2;

process main(void) {    
    s1 = semcreate(1);  
    s2 = semcreate(0);
    
    resume(create(producer, 1024, 20, "produser", 1, s1));
    resume(create(consumer, 1024, 20, "consumer", 1, s2));
  
    return OK;
}

void produser(void){
  int32 i;
  for  (i=1; i<=1001; i++){
    wait(s1);
    n++;
    signal(s2);
    sleepms(1000);
  }
}

void consumer(void){
  int32 i;
  for (i=1; i<1001; i++){
    wait(s2);
    printf("Nilai dari n adalah %d\n", n);
    signal(s1);
    sleepms(1000);
  }
}
