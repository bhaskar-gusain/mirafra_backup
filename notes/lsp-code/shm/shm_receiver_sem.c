#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

#define KB 1024
#define SEM_SIZE 4 //1024
int main(void)
{
	void *shm_addr = NULL;;
	char str[50] = {0};
	int shmid;

	sem_t *lock;
	int mutex_id;
	mutex_id = shmget((key_t)1211, SEM_SIZE, 0666|IPC_CREAT);
        lock = shmat(mutex_id, NULL,0);

	shmid = shmget((key_t)1234, KB, 0666|IPC_CREAT);
	if(shmid >= 0)
		printf("Shared memory created with shmid : %d\n", shmid);
	else
	{
		printf("Failed to create shared memory\n");
		exit(0);
	}
	shm_addr = shmat(shmid,NULL,0);

	printf("Entering Semaphore and count : %d\n", *((char*)lock));
//		sem_post(lock);
	sem_wait(lock);
	printf("After sem_wait and count : %d\n", *((char*)lock));
	printf("Entered Semaphore\n");
	if(shm_addr !=NULL)
		printf("Process attached at addr: %p\n", shm_addr);
	else
	{
		printf("Failed to attach the shared memory\n");
		exit(0);
	}
	strcpy(str, (char*)shm_addr);
	printf("Read string from the shamred memory is %s\n", str);
	shmdt(shm_addr);
	sem_post(lock);
	shmdt(lock);

	return 0;
}

