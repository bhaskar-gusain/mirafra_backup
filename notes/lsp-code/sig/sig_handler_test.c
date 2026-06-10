#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int cmd, pid;

	cmd = atoi(argv[1]);

	for(int i = 2; i<argc; i++)
	{
		pid = atoi(argv[i]);

		printf("%d	%d\n", pid, cmd);

		kill(pid, cmd);
	}

	return 0;
}

