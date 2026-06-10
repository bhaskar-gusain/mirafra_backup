#include </home/mirafra/Desktop/temp/header.h>

int main()
{
	char buff[10];
	mkfifo("ipc", 0666);
	int fd = open("ipc", O_RDONLY | O_NONBLOCK);
	//sleep(5);
	int n = read(fd , buff , sizeof(char)*10);


	if(n == -1)
	{
		perror("read");   // EAGAIN
	}
	else if(n == 0)
	{
		printf("No writer\n");
	}
	else
	{
		buff[n] = '\0';
		printf("%s\n", buff);
	}

	close(fd);
	return 0;
}
