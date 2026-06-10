// crash_lab.c
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>

/* ---------- Case 1: invalid pointer ---------- */
void crash_invalid_ptr(void) {
	printf("\n[case] invalid pointer\n");
	volatile uint32_t *p = (uint32_t *)0x1;   // clearly invalid
	//p = malloc(10);
	*p = 0xDEADBEEF;                          // 💥 SIGSEGV
}

/* ---------- Case 2: illegal instruction ---------- */
void crash_illegal_instruction(void) {
	printf("\n[case] illegal instruction\n");
//#ifdef COMM
#if defined(__x86_64__) || defined(__i386__)
	__asm__ volatile ("ud2");                 // 💥 SIGILL on x86
#elif defined(__arm__) || defined(__aarch64__)
	__asm__ volatile (".word 0xFFFFFFFF");    // 💥 likely SIGILL on ARM
#else
	raise(SIGILL);                            // fallback
#endif
//#endif
}

/* ---------- Case 3: stack overflow ---------- */
void deep_recursion(int depth) {
	char buf[1024];                           // grows stack each call
	buf[0] = (char)depth;                     // touch it so it’s not optimized out
	if (depth % 100 == 0) {
		printf("depth=%d\n", depth);
		//return;
	}
	deep_recursion(depth + 1);                // no base case → 💥
}

void crash_stack_overflow(void) {
	printf("\n[case] stack overflow\n");
	deep_recursion(1);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: %s [1|2|3]\n", argv[0]);
		return 0;
	}
	switch (argv[1][0]) {
		case '1': crash_invalid_ptr(); break;
		case '2': crash_illegal_instruction(); break;
		case '3': crash_stack_overflow(); break;
		default: printf("unknown\n");
	}
	return 0;
}
