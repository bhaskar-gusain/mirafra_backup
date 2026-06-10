savedcmd_irq.ko := ld -r -m elf_x86_64 -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T /usr/src/linux-headers-6.17.0-23-generic/scripts/module.lds -o irq.ko irq.o irq.mod.o .module-common.o
