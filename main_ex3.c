/*  main.c  - main */

#include <xinu.h>
void sndChar(char);

process	main(void)
{	
	resume(create(sndChar, 1024, 20, "Send A", 1,'A'));
	resume(create(sndChar, 1024, 20, "Send B", 1,'B'));
	return OK;
}

void sndChar(char c)
{
	
	while(1){
	printf("%c \n", c);
	sleepms(1000);
	}
	
}


