#include </home/mirafra/Desktop/temp/header.h>

int main()
{
	int client_fd ;
	struct sockaddr_in client;
	char buff[100];

	//socket
	client_fd = socket(AF_INET , SOCK_STREAM , 0);

	client.sin_family = AF_INET;
	client.sin_port = htons(8080);
	inet_pton(AF_INET, "127.0.0.1", &client.sin_addr);

	//connect

	connect(client_fd, (struct sockaddr*)&client , sizeof(client));




	strcpy(buff,"Hello ");

	send(client_fd,buff,strlen(buff) + 1 , 0);

	close(client_fd);

	return 0;
}
