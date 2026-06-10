// Calculation ----------

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <pthread.h>

int result;

void *(calculation)(void *arg)
{

	int n1, n2;
	char op;
	char *inp;
	inp = (char *)arg;

	n1 = *inp++ - '0';
	n2 = *inp++ - '0';
	op = *inp;

	//printf("%d %d %c", n1, n2, op);

	switch (op)
	{
	case '+':
		result = n1 + n2;
		break;
	case '-':
		result = n1 - n2;
		break;
	case '*':
		result = n1 * n2;
		break;
	case '/':
		result = n2 ? n1 / n2 : 0;
		break;
	default:
		printf("Invalid operator\n");
		exit(1);
	}

	return (void *)&result;
}

int main()
{

	char n1, n2, op;

	pthread_t t1;

	int id;
	id = shmget(1234, 1024, 0666 | IPC_CREAT);

	char *ptr = (char *)(shmat(id, NULL, 0));

	if (ptr == NULL)
	{
		perror("shmat");
	}


	pthread_create(&t1, NULL, &calculation, (void *)ptr);
	void *ret;
	pthread_join(t1, &ret);

	result = *(int *)ret;
	
	printf("Result is %d\n", result);

	shmdt(ptr);
	shmctl(id, IPC_RMID, NULL);

	return 0;
}
