#include </home/mirafra/Desktop/temp/header.h>

struct msgbuf
{
	long mtype;
	char mtext[100];
};


int main()
{
	struct msgbuf msg;
	
	int msgid = msgget(1234, 0777 | IPC_CREAT);
	
	if (msgrcv(msgid,&msg,sizeof(msg.mtext),2,0) == -1)
	{
		perror("message recv");
	}

	printf("%s\n",msg.mtext);

	msgctl(msgid,IPC_RMID,NULL);

	return 0;
}
