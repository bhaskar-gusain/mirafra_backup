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
#include <semaphore.h>

#define THREAD 2

int buff[10];
int count = 0;

sem_t isfull;
sem_t isempty;



pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;


void* producer(void* arg)
{
	while(1){
		int val = (rand() % 10);
		
		sem_wait(&isempty);

		pthread_mutex_lock(&lock1);
		
		buff[count] = val;
		count++;
		
		pthread_mutex_unlock(&lock1);
		sem_post(&isfull);
	}

}

void* consumer(void* arg)
{
	while(1){
		
		sem_wait(&isfull);
		pthread_mutex_lock(&lock1);

		int val = buff[count-1];
		count--;
		pthread_mutex_unlock(&lock1);
		sem_post(&isempty);
		printf("Value consumed is %d\n",val);
	}
}


int main()
{
	srand(time(NULL)); 
	
	//sem_t isfull , isempty;

	sem_init(&isfull , 0 , 0);
	sem_init(&isempty , 0 , 10);

	pthread_t p[THREAD];

	for(int i = 0 ; i<THREAD ; i++)
	{
		if(i%2 == 0)
		{
			pthread_create(&p[i], NULL , &producer,NULL  );
		}
		else{
			pthread_create(&p[i], NULL , &consumer, NULL );
		}
	}
	for(int i = 0 ; i<THREAD ; i++)
	{
		pthread_join(p[i],NULL);
	}
	sem_destroy(&isfull);
	sem_destroy(&isempty);


	return 0;
}
