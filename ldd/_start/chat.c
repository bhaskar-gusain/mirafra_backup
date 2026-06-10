#define SYS_WRITE 1
#define SYS_EXIT  60

// syscall wrappers
static long sys_write(int fd, const char *buf, long len)
{
    long ret;
    __asm__ volatile (
        "syscall"
        : "=a"(ret)
        : "a"(SYS_WRITE), "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory"
    );
    return ret;
}

static void sys_exit(int code)
{
    __asm__ volatile (
        "syscall"
        :
        : "a"(SYS_EXIT), "D"(code)
        : "rcx", "r11", "memory"
    );
    while (1);
}

static long my_strlen(const char *s)
{
    long len = 0;
    while (s[len]) len++;
    return len;
}

static void my_main(long argc, char **argv)
{
    char msg[] = "Inside my_main\n";
    sys_write(1, msg, sizeof(msg)-1);

    for (long i = 0; i < argc; i++)
    {
        sys_write(1, argv[i], my_strlen(argv[i]));
        sys_write(1, "\n", 1);
    }
}

__attribute__((naked))
void _start(void)
{
    __asm__ volatile (
        "mov %rsp, %rdi\n"   // pass stack pointer as arg
        "call start_c\n"
    );
}

void start_c(long *stack)
{
    long argc = stack[0];
    char **argv = (char **)&stack[1];

    my_main(argc, argv);

    sys_exit(0);
}
