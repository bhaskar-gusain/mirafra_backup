savedcmd_basic_driver.mod := printf '%s\n'   basic_driver.o | awk '!x[$$0]++ { print("./"$$0) }' > basic_driver.mod
