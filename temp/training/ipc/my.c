#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define fname "/tmp/my_fifo"

int main()
{

    int f1 = 0;

    int buff[4];
    mkfifo(fname, 0777);


    f1 = open(fname, O_WRONLY | O_NONBLOCK);

    read(f1,buff,sizeof(buff));

    switch (buff[1])
    {
    case '+':
        buff[3] = buff[0] + buff[2];
        break;
    case '-':
        buff[3] = buff[0] - buff[2];
        break;
    case '*':
        buff[3] = buff[0] * buff[2];
        break;
    case '/':
        buff[3] = buff[0] / buff[2];
        break;
    default:
        printf("Invalid operator\n");
        exit(1);
    }

    close(f1);

    return 0;
}