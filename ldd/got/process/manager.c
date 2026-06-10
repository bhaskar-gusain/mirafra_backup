#include <stdio.h>
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>

int i = 0;


void handler()
{
	i++;
	printf("interrupt generated %d\n",i);
}

int main()
{
	//pid_t pid;	
	
	//signal(SIGINT,handler);
	
	//while(1);	
	
	printf("Hello\n");
	printf("World");
	return 0;
}
