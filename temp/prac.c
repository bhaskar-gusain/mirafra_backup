#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"

int main(int argc , char** argv)
{
	pid_t pid;

	printf("function");
	fflush(stdout);
	pid = fork();
	if(pid == 0)
	{
		printf("child\n");
	}
	else
	{
		printf("parent\n");
	}

	
	return 0;
}
