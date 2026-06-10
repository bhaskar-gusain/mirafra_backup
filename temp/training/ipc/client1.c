#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/shm.h>

int main()
{
    char inp[3] ;
    char op;

    int id;
    id = shmget(1234, 1024, 0666 | IPC_CREAT);

    char *ptr = (char *)(shmat(id, NULL, 0));

    if (ptr == NULL)
    {
        perror("shmat");
    }

    printf("Enter the no.\n");
    fflush(stdin);
    scanf("%c %c", &inp[0], &inp[1]);

    printf("Enter the operator. ");
    fflush(stdout);
    scanf("\n%c", &inp[2]);

   
    strcpy(ptr, inp);

    shmdt(ptr);

    return 0;
}