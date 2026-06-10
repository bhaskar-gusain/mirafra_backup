savedcmd_mprobe.mod := printf '%s\n'   mprobe.o | awk '!x[$$0]++ { print("./"$$0) }' > mprobe.mod
