ENTRY(Reset_Handler)

MEMORY
{
	FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
	SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
	.isr_vector :
	{
		KEEP(*(.isr_vector))
    } > FLASH

    .text :
    {
	    *(.text*)
		    *(.rodata*)
		    . = ALIGN(4);
		    _etext = .;
    } > FLASH

    .data : AT (_etext)
    {
	    _sdata = .;
	    *(.data*)
	    . = ALIGN(4);
	    _edata = .;
    } > SRAM

    .bss :
    {
	    _sbss = .;
	    *(.bss*)
		    *(COMMON)
		    . = ALIGN(4);
		    _ebss = .;
    } > SRAM

    _estack = ORIGIN(SRAM) + LENGTH(SRAM);
}
