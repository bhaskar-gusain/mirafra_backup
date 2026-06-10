#include "stdio.h"
#include "stdlib.h"

struct t{
	char a;
	int32_t b;
	char c;


};


int main()
{
/*	const int x = 15;
	int sum = 0;
	printf("old value of x - %d\n",x);


	int *ptr = (int *)&x;

	*ptr = 1;

	printf("new value of x - %d\n",x);
	
	sum = x + 10;
	printf("value of sum - %d\n",sum);
	*/
	printf("value of sum - %ld\n",sizeof(struct t));

	return 0;
}
