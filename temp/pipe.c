#include "header.h"

int main()
{
	int fd[2];
	pid_t p;
	char buff[20] ,inp[20];
	pipe(fd);
	p =fork();

	if(p == 0)
	{
		close(fd[1]);

		while(1){
			//			sleep(1);
			printf("Child process ....\n");
			read(fd[0] , buff , 20);
			printf("Buffer is %s\n",buff);
		}
	}
	else
	{
		close(fd[0]);

		while(1){
			//			sleep(2);
			printf("Parent process ...\n");
			printf("Enter data...\n");
			scanf("%s",inp);
			write(fd[1],inp,sizeof(inp));
		}

		wait(NULL);

	}
	return 0;
}
