#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	printf("I am parent : %u\n",getpid());

	pid_t pid = fork();

	if(pid < 0)
	{
		printf("Fork failed...\n");
		exit(1);
	}

	if(pid == 0)
	{
		printf("I am child process : %u\n", getpid());
		execl("/mnt/d/Code_WS/LSP/linux_system_programming/process/hello","./hello",NULL);
		printf("Done with Child\n");
		exit(0);
	}
	else
		printf("I am in parent process : %u\n", getpid());

	getchar();

	return 0;
}
