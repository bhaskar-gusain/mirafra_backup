#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

int main()
{
	int inp = 0b11010; 
	int x = 0;
	int i = 0;

	unsigned temp = inp; 

	if(inp < 0)
	{
		temp = inp - 0b1;
		temp = ~temp;
	}
	while(temp != 0)
	{
		x = x + (temp & 1) * pow(2,i);
		temp = temp >> 1;
		i++;
	}

	if(inp < 0) x=-x;

	printf("%d\n",x);

	return 0;
}
