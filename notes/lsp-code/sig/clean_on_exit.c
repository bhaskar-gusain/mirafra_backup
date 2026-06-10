#include <stdio.h>
#include <stdlib.h>

int *p = NULL;
void cleanup(void)
{
	if(p != NULL)
	{
		free(p);
		p = NULL;
		printf("Cleaning up...\n");
	}

	printf("I'm Done\n");
}


int main()
{
	printf("Hello\n");
	p = (int *)malloc(10);
	atexit(cleanup);
	pause();
	printf("Hey\n");

	free(p);
	p = NULL;

	return 0;
}
