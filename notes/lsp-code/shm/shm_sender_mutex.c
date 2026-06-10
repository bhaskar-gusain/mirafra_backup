#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define KB 3000


int main(void)
{
	void *shm_addr = NULL;
	char str[50];
	int shmid;
	pthread_mutexattr_t attr;

	int mutex_id;
        mutex_id = shmget((key_t)1211, 4, 0666|IPC_CREAT);
	pthread_mutex_t *lock;
        lock = shmat(mutex_id, NULL,0);
	
	// Initialize attribute object
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(lock, &attr);
	
	shmid = shmget((key_t)12345, KB, 0666|IPC_CREAT);

	if(shmid >= 0)
		printf("Shared memory created with shmid : %d\n", shmid);
	else
	{
		printf("Failed to create shared memory %d %d\n",shmid, errno);
		exit(0);
	}
	pthread_mutex_lock(lock);
	shm_addr = shmat(shmid,NULL,0);
	memset(shm_addr, 0, KB);
	if(shm_addr !=NULL)
		printf("Process attached at addr: %p\n", shm_addr);
	else
	{
		printf("Failed to attach the shared memory\n");
		exit(0);
	}
	printf("Enter the string to send\n");
	read(0, str, 50);
	strncpy((char*)shm_addr, str,strlen(str)+1);

	printf("Written string into the shamred memory is %s\n",(char*)shm_addr);

	shmdt(shm_addr);
	
	getchar();

	pthread_mutex_unlock(lock);
	shmdt(lock);
	return 0;
}

