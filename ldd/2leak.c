#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

void heap_overflow()

{

	printf("\n[1] Heap Buffer Overflow\n");

	int *ptr;

	ptr = (int *)malloc(5 * sizeof(int));

	/* Writing beyond allocated memory */

	for (int i = 0; i < 5; i++)

	{

		ptr[i] = i;

	}

	free(ptr);

}

void stack_overflow()

{

	printf("\n[2] Stack Buffer Overflow\n");

	char buffer[8];

	for (int i = 0; i < 8; i++)

	{

		buffer[i] = 'A';

	}

}

void use_after_free()

{

	printf("\n[3] Use After Free\n");

	int *ptr;

	ptr = malloc(sizeof(int));

	*ptr = 100;

	free(ptr);

	/* Illegal access */

	//printf("Value = %d\n", *ptr);

}

void undefined_behavior()

{

	printf("\n[4] Undefined Behavior\n");

	int x = INT_MAX;

	//x = x + 1;

	printf("x = %d\n", x);

}

void memory_leak()

{

	printf("\n[5] Memory Leak\n");

	int *ptr;

	ptr = malloc(100);

	/* Forgot free() */

	free(ptr);
}

int main()

{

	heap_overflow();

	stack_overflow();

	use_after_free();

	undefined_behavior();

	memory_leak();

	return 0;

}

