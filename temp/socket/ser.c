#include </home/mirafra/Desktop/temp/header.h>

int main()
{
	int client_fd , server_fd;
	struct sockaddr_in client , server;
char buff[100];

	//socket
	server_fd = socket(AF_INET , SOCK_STREAM , 0);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8080);

	//bind
	bind(server_fd, (struct sockaddr *)&server, sizeof(server));


	//listen
	listen(server_fd, 5);

	//accept
	socklen_t len = sizeof(client);
	client_fd = accept(server_fd , (struct sockaddr *) &client , &len);
	
	int ret = recv(client_fd,buff,sizeof(buff),0);

	if(ret == 0)
	{
		return 1;
	}
	else if(ret > 0) {

		printf("received - %s\n",buff);
	}



	send(client_fd,buff,sizeof(buff),0);

	close(client_fd);
	close(server_fd);	
	
	return 0;
}
