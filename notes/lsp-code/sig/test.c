#include <stdio.h>

int main()
{
	char *s[] = {
		[2] = "Two",
		[0] = "Zero",
		[1] = "Three"
	};

	printf("%s\n",s[1]);

return 0;
}
