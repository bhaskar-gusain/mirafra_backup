#include </home/mirafra/Desktop/temp/header.h>

struct msgbuf
{
	long mtype;
	char mtext[100];
};


int main()
{
	struct msgbuf msg;
	msg.mtype = 2;
	strcpy(msg.mtext,"Hi How are you?");
	int msgid = msgget(1234,IPC_CREAT | 0777);

	printf("msgid - %d\n",msgid);

	printf("%s",msg.mtext);
	msgsnd(msgid,&msg,sizeof(msg.mtext),0);
	printf("Message send successfully\n");

	return 0;
}
