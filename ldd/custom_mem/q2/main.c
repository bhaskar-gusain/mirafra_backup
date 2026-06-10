#include <stdint.h>

/* .data (initialized, must be copied from FLASH to RAM) */
uint32_t g_init = 0x12345678;

/* .bss (zeroed by startup) */
uint32_t g_zero;

int main(void)
{
	/* Put a breakpoint here in GDB */
	volatile uint32_t check1 = g_init;  /* expect 0x12345678 */
	volatile uint32_t check2 = g_zero;  /* expect 0 */

}
