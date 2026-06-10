#include <stdio.h>

int main()
{


	union test {
		int x;
		char arr[4];
	};

	union test t;

	t.x = 0x12345678;

	printf("%x\n", t.arr[0]);
}
