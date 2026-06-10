#include </home/mirafra/Desktop/temp/header.h>

int main()
{
	int shmid = shmget(69,100,0666 | IPC_CREAT);

	char *ptr = (char*)shmat(shmid,NULL,0);	

	if(ptr == (void*)-1)
	{
		perror("shmat");

	}
	
	strcpy(ptr,"Hate me");
	printf("Data written to shared memory\n");

	shmdt(ptr);

	
	return 0;
}
