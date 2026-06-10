#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "apple,banana,cherry,mango";
	char *token = strtok(str, ",");       // first call: pass the string

	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, ",");        // subsequent calls: pass NULL
	}
	return 0;
}
