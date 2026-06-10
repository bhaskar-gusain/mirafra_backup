#include <err.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

void *fn(void *arg)
{
	int val = *(int*)arg;

	int sum=0;

	for(int i = 0; i<=val ; i++)
	{
		sum += i;
	}
	return (void*) sum;
}


int main(int argc , char *argv[])
{
	int ans=0;

	if(argc != 2)
	{
		printf("Wrong input\n");
		exit(0);
	}
	int val = atoi(argv[1]);

	pthread_t t;

	int x = atoi(argv[1]);

	pthread_create(&t, NULL , fn , &val );

	pthread_join(t,(void*) &ans);




	printf("Sum %d\n",ans);



	return 0;
}
