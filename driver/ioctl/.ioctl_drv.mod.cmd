savedcmd_ioctl_drv.mod := printf '%s\n'   ioctl_drv.o | awk '!x[$$0]++ { print("./"$$0) }' > ioctl_drv.mod
