#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	char write_buf[] = "Hello from User Space!";
	char read_buf[100];

	fd = open("/dev/basic_char", O_RDWR);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}

	write(fd, write_buf, strlen(write_buf));

	lseek(fd, 0, SEEK_SET);  

	int n = read(fd, read_buf, sizeof(read_buf));
	read_buf[n] = '\0';

	printf("Read from driver: %s\n", read_buf);

	close(fd);
	return 0;
}
