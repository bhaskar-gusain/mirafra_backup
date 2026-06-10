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

    int f2 = 0;

    int buff[4];
    mkfifo(fname, 0777);

    f2 = open(fname, O_WRONLY | O_NONBLOCK);

    printf("Enter first number: ");
    scanf("%d", &buff[0]);

    printf("Enter operator (+ - * /): ");
    scanf(" %d", &buff[1]);

    printf("Enter second number: ");
    scanf("%d", &buff[2]);

    write(f2, buff, sizeof(buff));

    close(f2);
}