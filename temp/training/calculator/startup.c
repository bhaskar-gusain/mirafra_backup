#include <stdint.h>

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
extern uint32_t _estack;

int main(void);

void Reset_Handler(void);
void Default_Handler(void);

// Weak aliases
void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));

// Vector table
__attribute__((section(".isr_vector")))
uint32_t vector[] = {
	(uint32_t)&_estack,
	(uint32_t)Reset_Handler,
	(uint32_t)NMI_Handler,
	(uint32_t)HardFault_Handler
};

void Reset_Handler(void)
{
	uint32_t *src = &_etext;
	uint32_t *dst = &_sdata;

	// Copy .data
	while (dst < &_edata)
	{
		*dst++ = *src++;
	}

	// Clear .bss
	dst = &_sbss;
	while (dst < &_ebss)
	{
		*dst++ = 0;
	}

	main();

	while (1);
}

void Default_Handler(void)
{
	while (1);
}
