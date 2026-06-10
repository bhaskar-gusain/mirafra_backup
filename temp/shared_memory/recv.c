#include </home/mirafra/Desktop/temp/header.h>

int main()
{       
        int shmid = shmget(69,100,0666 | IPC_CREAT);

        char *ptr = (char*)shmat(shmid,NULL,0);

	printf("%s",ptr);

	shmdt(ptr);
	shmctl(shmid,IPC_RMID,NULL);

        
        return 0;
}  
