#include <stdio.h>

typedef int (*operation)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return b ? a / b : 0; }

int main()
{
	operation ops[] = {add, sub, mul, divide};

	int a, b, choice;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	printf("0:Add 1:Sub 2:Mul 3:Div\n");
	scanf("%d", &choice);

	if (choice < 0 || choice > 3)
	{
		printf("Invalid choice\n");
		return 1;
	}

	printf("Result = %d\n", ops[choice](a, b));

	return 0;
}
