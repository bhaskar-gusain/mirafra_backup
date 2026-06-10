#include </home/mirafra/Desktop/temp/header.h>

int num = 0;


void sigint_handler(int signum)
{
	printf("Inside SIGINT Handler \n");
	if(num <  1 )
	{
		raise(SIGINT);	raise(SIGUSR1);	raise(SIGINT);
	}
	num ++;
	printf("Out of Signal Handler \n");
}

void sigusr1_handler(int signum)
{
	printf("Inside SIGUSR1 Handler \n");
}


int main()
{	char nam[30];
	printf("Registering Signal Handler \n");
	signal(SIGINT,sigint_handler);
	signal(SIGUSR1,sigusr1_handler);
	printf("Enter Your Name \n");
	scanf("%s",nam);
	printf("%s : Your Name is So Sweet \n",nam);
	return 0;
}
