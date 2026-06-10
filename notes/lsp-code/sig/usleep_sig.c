#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	int pid;

	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed\n");
		exit(0);
	}

	if(pid == 0)
	{
		while(1)
		{
			printf("Hey!!! how are you\n");
		}
	}
	else
	{
		static int i;
		while(i++ <=10) usleep(50000);
		
		kill(pid,SIGKILL);
//		wait(NULL);
	}
	return 0;
}
