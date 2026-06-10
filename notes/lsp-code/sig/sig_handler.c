#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int n = 0;
void sig_handler(int);

int *p = NULL;

int main(void)
{
	signal(SIGSEGV, sig_handler);
	//while(1)
	{
		sleep(1);
		printf("Counting... %d\n",n++);
	}
	*p = 20;

	printf("Hello\n");

	return 0;
}

void sig_handler(int signum)
{
	printf("Signal %d handled\n",signum);
	//reset counter
	p = &n;
	n = 100;
	printf("%p    %d\n", p,*p);
	sleep(2);
}
