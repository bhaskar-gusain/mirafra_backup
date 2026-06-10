#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct
{
	int a;
	int b;
	char op;
} Data;

int main()
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return 1;
	}

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return 1;
	}

	//CHILD PROCESS → Calculator
	if (pid == 0)
	{
		close(fd[1]); // close write end

		Data d;
		read(fd[0], &d, sizeof(d));

		int result;

		switch (d.op)
		{
			case '+': result = d.a + d.b; break;
			case '-': result = d.a - d.b; break;
			case '*': result = d.a * d.b; break;
			case '/': result = (d.b != 0) ? d.a / d.b : 0; break;
			default:
				  printf("Invalid operator\n");
				  exit(1);
		}

		printf("Child Process: %d %c %d = %d\n", d.a, d.op, d.b, result);

		close(fd[0]);
	}

	// PARENT PROCESS → Input
	else
	{
		close(fd[0]); // close read end

		Data d;

		printf("Enter first number: ");
		scanf("%d", &d.a);

		printf("Enter operator (+ - * /): ");
		scanf(" %c", &d.op);

		printf("Enter second number: ");
		scanf("%d", &d.b);

		write(fd[1], &d, sizeof(d));

		close(fd[1]);
		wait(NULL);
	}

	return 0;
}
