#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int n = 0;
void sig_handler(int);

int main(void)
{
	setpgid(999, getpid());
	pid_t pgid = getpgrp(); // Get current process group ID
	printf("Process Group : %d\n", pgid);
	signal(SIGTERM, sig_handler);
	while(1)
	{
		sleep(1);
		printf("Counting... %d\n",n++);
	}

	return 0;
}

void sig_handler(int signum)
{
	printf("Signal %d handled\n",signum);

	n = 0;
}
