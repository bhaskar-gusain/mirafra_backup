#include "header.h"



int main()
{
	pid_t p;
	int fd1 , fd2;
	char buff[20];

	mkfifo("f1",0666);
	perror("mkfifo");

	mkfifo("f2",0666);
	perror("mkfifo");

	p = fork();

	fd1 = open("f1" , O_RDWR);
	fd2 = open("f2" , O_RDWR);

	if(p != 0)
	{

		while(1)
		{
			printf("Enter data..\n");
			scanf("%s",buff);
			int ret = write(fd1,buff,strlen(buff)+1);



			if(ret < 0)
			{
				perror("write failed");
				printf("Child is closed. Exiting parent...\n");
				close(fd1);
				close(fd2);
				exit(0);
			}

			if(strcmp(buff, "exit") == 0)
			{
				printf("Exiting parent...\n");
				close(fd1);
				close(fd2);
				exit(0);
			}
		}


	}
	else
	{
		while(1)
		{
			read(fd2,buff,sizeof(buff));
			printf("%s\n",buff);
			if(!strcmp(buff,"exit"))
			{
				printf("Exiting...\n");
				close(fd1);
				close(fd2);
				exit(0);
			}
		}
	}

	return 0;
}
