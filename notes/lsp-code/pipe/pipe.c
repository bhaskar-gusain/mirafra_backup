#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
#include <unistd.h>
//#include <assert.h>
#include <string.h>

int main(void)
{
	pid_t pid = -1;
	int fd[2];
	int ret = pipe(fd);
	    

	printf("This is process ID: %d   ppid = %d\n", getpid(),getppid());
	
	pid = fork();
	
	if(pid == 0)
	{
		close(fd[0]);
		char str[]="abcd";
		printf("This is child process and ID: %d\n", getpid());
		printf("Started writing to a pipe\n");
		write(fd[1], str, strlen(str));

		write(fd[1], "xyz", strlen("xyz"));
		char str2[] = "abcdmnc123456";
		write(fd[1], str2, sizeof(str2));

		close(fd[1]);
		printf("End of writing into a pipe\n");
	}
	else{
		close(fd[1]);
		char str[25];
		printf("This is parent process and ID: %d\n", getpid());
		printf("Started reading from pipe\n");
		//sleep(2);
		read(fd[0], str, 4);

		printf("Received string : %s\n", str);

		memset(str,0,5);

		read(fd[0], str, 3);
		printf("Received string : %s\n", str);
		memset(str,0,5);
		read(fd[0], str, 13);
		printf("Received string : %s\n", str);
		
		close(fd[0]);
		printf("End of reading from pipe\n");
	}

	pid = fork();
	if(pid != 0)
		printf("This is parent2 process and ID: %d   ppid = %d\n", getpid(),getppid());
	else
	{
		char str[20];
		printf("This is child2 process and ID: %d   ppid = %d\n", getpid(),getppid());
                printf("Started reading from pipe\n");
                read(fd[0], str, 4);
		printf("Received string : %s\n", str);
	}

	return 0;
}
