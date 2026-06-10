#include <stdint.h>
#include "calc.h"

volatile int result1, result2, result3, result4;

int main(void)
{
	int a = 20;
	int b = 10;

	result1 = add(a, b);
	result2 = sub(a, b);
	result3 = mul(a, b);
	result4 = divi(a, b);

	while (1)
	{
		// loop forever
	}
}
