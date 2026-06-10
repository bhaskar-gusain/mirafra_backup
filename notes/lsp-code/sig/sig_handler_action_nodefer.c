#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <execinfo.h>

void sig_handler(int);
int *p = NULL;
int n = 10;

int main(void)
{
	struct sigaction action;
	char buf[20];

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESETHAND;//SA_RESETHAND;//SA_NODEFER;//SA_RESTART;

	sigaction(SIGSEGV, &action, NULL);

	*p = 20;

	printf("*p = %d\n",*p);

/*	while(1)
	{
		memset(buf,0,20);
		printf("Enter string\n");
		int ret = read(0, buf, 20);//scanf("%s",buf);
		printf("scanf retured %d with error code %d and str: %s\n", ret, errno,buf);
	}
*/	return 0;
}

void sig_handler(int signum)
{
	int i = 0;
	printf("Entered into the handler\n");
	//while(i<10)
	{
		sleep(1);
		printf("Signal %d handled\n",signum);
		i++;
	}
	void *array[10];
    size_t size;
	// get void*'s for all entries on the stack
    size = backtrace(array, 10);
    fprintf(stderr, "Error: signal %d:\n", signum);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}
