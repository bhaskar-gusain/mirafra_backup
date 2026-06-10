ENTRY(_start)

SECTIONS
{
	. = 0x2000;
	.text :
	{
			*(.text)
			*(.rodata)
			. = ALIGN(4);
    }

    . = 0x3000;
    .data :
    {
	    *(.data)
	    . = ALIGN(4);
    }

    . = 0x4000;
    .bss :
    {
	    *(.bss)
		    *(COMMON)
		    . = ALIGN(4);
    }
}

