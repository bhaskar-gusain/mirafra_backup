/* linker.ld — AArch64 cross compilation (aarch64-linux-gnu-gcc) */

OUTPUT_FORMAT("elf64-littleaarch64")   /* 64-bit little-endian ARM ELF */
OUTPUT_ARCH(aarch64)                   /* target architecture          */

ENTRY(_start)                          /* libc _start → calls main()   */

SECTIONS
{
    /* ── Standard Linux userspace load address for AArch64 ── */
    . = 0x400000;

    /* ── Code ─────────────────────────────────────────────── */
    .text : ALIGN(4096) {
        *(.text)
        *(.text.*)
        *(.init)               /* libc init routines              */
        *(.fini)               /* libc fini routines              */
        . = ALIGN(8);
    }

    /* ── Read-only data (constants, string literals) ───────── */
    .rodata : ALIGN(8) {
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(8);
    }

    /* ── Initialized global/static variables ───────────────── */
    .data : ALIGN(8) {
        *(.data)
        *(.data.*)
        . = ALIGN(8);
    }

    /* ── Uninitialized globals (zeroed at startup by libc) ─── */
    .bss : ALIGN(8) {
        __bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(8);
        __bss_end = .;
    }

    /* ── Dynamic linking support (shared libs / libc) ──────── */
    .dynamic   : { *(.dynamic)   }
    .got       : { *(.got)       }
    .got.plt   : { *(.got.plt)   }
    .plt       : { *(.plt)       }

    /* ── Discard unwanted sections ──────────────────────────── */
    /DISCARD/ : {
        *(.note.GNU-stack)
        *(.gnu_debuglink)
    }
}
