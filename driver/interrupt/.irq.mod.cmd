savedcmd_irq.mod := printf '%s\n'   irq.o | awk '!x[$$0]++ { print("./"$$0) }' > irq.mod
