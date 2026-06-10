#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgQ.h"

int main(int argc, char *argv[])
{
	struct msgbuf msg; // = {1, "Hello"};

	/*	{
		{1,"Test MSG1"},
		{1,"Test MSG11"},
		{2, "Test MSG2"}
		};  */

	key_t key;
	int msgid;
	key = ftok(pathname, proj_id);

	if(key < 0)
	{
		printf("Failed to create key %d\n",errno);
		exit(0);
	}

	printf("Size: %ld   Key: %d\n", sizeof(msg),key);

	msgid = msgget(key, 0666|IPC_CREAT);

	msg.mtype = atoi(argv[1]);
	strcpy(msg.mtext, argv[2]); 

	if(msgid < 0)
	{
		printf("Failed to create msgq %d\n",errno);
		exit(0);
	}else
		printf("msgID: %d\n",msgid);

//	for(int i = 0; i<3; i++)
	{
		if(msgsnd(msgid, (void*)&msg, strlen(msg.mtext) + 1, 0) < 0)
			perror("msgsend");
		else
			printf("%s msg of type: %ld sent\n",msg.mtext, msg.mtype);
	}
	msgctl(key, IPC_RMID, NULL);

	return 0;
}
