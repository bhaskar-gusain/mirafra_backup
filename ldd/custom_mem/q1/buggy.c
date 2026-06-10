#include <stdio.h>
#include <string.h>

void deep_bug(const char *input) {
	char buf[8];                 // small buffer on stack
	int guard = 0xDEADBEEF;      // sentinel we expect to stay intact

	printf("[deep_bug] guard before = 0x%x\n", guard);

	strcpy(buf, input);

	printf("[deep_bug] buf = %s\n", buf);
	printf("[deep_bug] guard after  = 0x%x\n", guard); // may change!

	// Use guard to make corruption visible
	if (guard != 0xDEADBEEF) {
		printf("[deep_bug] guard CORRUPTED!\n");
	}
}

void level3(const char *s) {
	deep_bug(s);
}

void level2(const char *s) {
	level3(s);
}

void level1(const char *s) {
	level2(s);
}

int main(void) {
	// Long string triggers overflow (adjust length to see “unpredictable” behavior)
	const char *payload = "AAAAAAAAAAAAAAAAAAAA"; // > 8 bytes

	level1(payload);

	printf("[main] returned normally\n");
	return 0;
}
