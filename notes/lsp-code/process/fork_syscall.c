#define _GNU_SOURCE
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid=vfork();
	return 0;
}
