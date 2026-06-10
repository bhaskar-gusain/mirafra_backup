#include </home/mirafra/Desktop/temp/header.h>

void parent_sigint_handler(int signum)
{	
	printf("Inside Parent Signal Handler \n");
}
int main()
{	int pid;
	printf("Registering Signal Handler \n");
	signal(SIGINT,parent_sigint_handler);
	pid = fork();
	if(pid == 0)
	{
		printf("Inside Child Process \n");
		sleep(5);
		printf("Child is sending signal to Parent \n");
		kill(getppid(),SIGINT);
		printf("End of Child Process \n");
	}
	else
	{
		signal(SIGINT,parent_sigint_handler);
		printf("Inside Parent Process \n");
		pause();
		printf("End of Parent Process \n");
	}
	return 0;
}
