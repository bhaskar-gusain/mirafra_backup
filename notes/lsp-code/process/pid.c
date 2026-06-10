#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	printf("Hello World pid: %d...ppid : %d\n",getpid(), getppid());
	getchar();
	return 0;
}

