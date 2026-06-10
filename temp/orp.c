#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{
	pid_t pid = fork();

	if(pid == 0)  // Child
	{

		printf("Child process\n");
		printf("Child PID: %d\n", getpid());
		printf("New Parent PID: %d\n", getppid());
		exit(0);
	}

	sleep(30);
	printf("Parent waiting for child...\n");

	return 0;
}
