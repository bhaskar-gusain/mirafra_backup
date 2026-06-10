#include <stdint.h>

void _start()
{
	int main();
	int ret = main();
	//_exit(ret);   
}

/* 🔴 Global initialized → .data */
int g_init = 10;

/* 🔵 Global uninitialized → .bss */
int g_uninit;

/* 🟡 Static initialized → .data */
static int s_init = 20;

/* 🟢 Static uninitialized → .bss */
static int s_uninit;

/* 🟣 Const → .rodata (FLASH) */
const int g_const = 30;

/* 🟠 Static const → .rodata */
static const int s_const = 40;

int main(void)
{
    static int func_static = 50;   // .data (initialized static)

    volatile int local = 60;       // stack

    while (1);
}
