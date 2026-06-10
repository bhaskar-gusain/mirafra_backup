#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int gData = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *inc(void *ignore)
{
	int flag = 0;
	printf("inc is called.............\n");
	while(1)
	{
	pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock);
		while(gData <= 10)
		{
		printf("Before update gData: %d in %s\n",gData,__func__);
		gData++;
		sleep(1);
		printf("After  update gData: %d in %s\n",gData,__func__);
		}
		if(gData > 10)
			break;
	}
	pthread_mutex_unlock(&lock);
	
}

void *dec(void *ignore)
{
	int flag = 0;
	printf("dec is called.............\n");
	while(1)
	{
	pthread_mutex_unlock(&lock);
		pthread_mutex_lock(&lock);
		while(gData > 0)
		{
		
			printf("Before update gData: %d in %s\n",gData,__func__);
			gData--;
			sleep(1);
			printf("After  update gData: %d in %s\n",gData,__func__);
		
		}
		if(gData <= 0)
			break;
	}
	pthread_mutex_unlock(&lock);
	
}

int main(void)
{
	pthread_t t1, t2;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&t1, NULL, inc, NULL);
	pthread_create(&t2, NULL, dec, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("Shared data value is : %d\n", gData);
	return 0;
}

