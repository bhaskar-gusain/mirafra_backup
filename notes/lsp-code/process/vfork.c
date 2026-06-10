#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int x =10;
int main(int argc, char *argv[])
{
    pid_t pid;

    pid=vfork();
    
    if (pid==0)
    {
	printf("I am a child process: %d\n",x);
	printf("Child process ID : %d \n", getpid());
	execl("/bin/ls", "ls", NULL);
        printf("Child's Parent process ID : %d\n",getppid());
	x = 20;
    }  
    else
    {
	printf("I am a parent process %d\n",x);
	printf("Parent process ID : %d \n",getpid());
	sleep(5);
	printf("Parent's parent ID(Shell id) : %d\n",getppid());
    }
    return 0;
}
