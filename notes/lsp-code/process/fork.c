#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int a = 5;

int main(void)
{
	int x = 100;
	int y = 123;
	pid_t pid = -1;

	pid = fork();

	printf("pid: %d\n",pid);

	if(pid == 0)
	{
		printf("Myself child process and my id : %d and my parent id : %d\n", 
				getpid(), getppid());
		x = 200;
		a = 10;
		y = 345;
		printf("c: x= %d &x = %p\n",x, &x);
		printf("c: y= %d &y = %p\n",y, &y);
		printf("c: a= %d &a = %p\n",a, &a);
		printf("c: main= %p\n", main);
	}
	else
	{
		printf("Myself parent process and my id : %d and my parent id : %d\n", 
				getpid(), getppid());
		x = 300;
		a = 20;
		y = 789;
		printf("x= %d &x = %p\n",x, &x);
		printf("y= %d &y = %p\n",y, &y);
		printf("a= %d &a = %p\n",a, &a); 
		printf("main= %p\n", main);
	}
	printf("%p  %p\n", printf, main);
	while(1){}
	return 0;
}


