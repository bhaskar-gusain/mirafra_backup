#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

#define KB 1024

pthread_mutex_t *lock = NULL;

int main(void)
{
	void *shm_addr = NULL;;
	char str[20];
	int shmid;

	int mutex_id;
        mutex_id = shmget((key_t)1211, 4, 0666|IPC_CREAT);
        lock = shmat(mutex_id, NULL,0);

	shmid = shmget((key_t)12345, KB, 0666);
	if(shmid >= 0)
		printf("Shared memory created with shmid : %d\n", shmid);
	else
	{
		printf("Failed to create shared memory\n");
		exit(0);
	}
	pthread_mutex_unlock(lock);
	pthread_mutex_lock(lock);
	shm_addr = shmat(shmid,NULL,0);

	if(shm_addr !=NULL)
		printf("Process attached at addr: %p\n", shm_addr);
	else
	{
		printf("Failed to attach the shared memory\n");
		exit(0);
	}
	printf("String read from shared memory is %s\n",(char*)shm_addr);

	shmdt(shm_addr);
	pthread_mutex_unlock(lock);
	shmdt(lock);
	return 0;
}

