/*  main.c  - main */

#include <xinu.h>
void sndA(void);
void sndB(void);

process	main(void)
{	

	sndA();
	sndB();
	return OK;    	
}

void sndA(void)
{
	
	while(1){
	printf("A\n");
	sleepms(1000);
	}
	
}

void sndB(void)
{
	
	while(1){
	printf("B\n");
	sleepms(1000);
	}
	
}


