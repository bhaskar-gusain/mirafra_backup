#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    setpgid(999, getpid());
    pid_t pgid = getpgrp(); // Get current process group ID
    printf("Process Group : %d\n", pgid);
    kill(-pgid, SIGTERM);   // Send SIGTERM to all processes in the group
    return 0;
}

