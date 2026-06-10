#include <stdio.h>
#include <stdlib.h>

void _start()
{

	int main2();
	int ret = main2();
	exit(ret);
}


int main2()
{
	printf("Hello from custom main\n");
	return 0;
}
