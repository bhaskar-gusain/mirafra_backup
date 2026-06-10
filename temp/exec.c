#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{


	printf("Inside Exec....\n");

	//char *arg[] = {"./a.out", NULL};

	execl("/home/mirafra/Desktop/temp/a.out" , "./a.out" , NULL);

	return 0;
}

