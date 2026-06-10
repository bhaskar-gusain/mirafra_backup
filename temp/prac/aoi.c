#include <stdio.h>

int glob1;
int glob2 = 25;


int main()
{
	int y , x = 10;
	printf("Local uninitialized - %d , Local initialized - %d\n",y,x);
	printf("Global uninitialized - %d , Global initialized - %d\n",glob1,glob2);


}

