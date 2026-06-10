#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int status;

	pid = fork();

	if(pid == 0)
	{
		int *p = NULL;
		printf("I am child process : %d\n", getpid());
	//	pause();
		sleep(5);
		*p = 4;
		exit(5);
	}
	else
	{
		wait(&status);
		if(WIFEXITED(status))
			printf("Child Exited with status : %d\n", WEXITSTATUS(status));
		if(WIFSIGNALED(status))
			printf("Child Exited on SIGNAL %d status : %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));

	}
	return 0;
}
