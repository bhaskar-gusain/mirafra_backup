#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define GPIO_BASE  0x3F200000   // Example (Raspberry Pi 3)
#define BLOCK_SIZE 4096

// GPIO registers
#define GPFSEL1 1   // Function select
#define GPSET0  7   // Set output
#define GPCLR0  10  // Clear output

int main()
{
	int mem_fd;
	void *gpio_map;
	volatile unsigned int *gpio;

	// Open /dev/mem
	mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (mem_fd < 0) {
		perror("open");
		return -1;
	}

	// Map GPIO
	gpio_map = mmap(
			NULL,
			BLOCK_SIZE,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			mem_fd,
			GPIO_BASE
		       );

	if (gpio_map == MAP_FAILED) {
		perror("mmap");
		return -1;
	}

	gpio = (volatile unsigned int *)gpio_map;

	// Configure GPIO17 as output
	int pin = 17;
	int reg = pin / 10;
	int shift = (pin % 10) * 3;

	gpio[GPFSEL1] &= ~(7 << shift);   // clear
	gpio[GPFSEL1] |=  (1 << shift);   // set as output

	while (1)
	{
		// LED ON
		gpio[GPSET0] = (1 << pin);
		sleep(1);

		// LED OFF
		gpio[GPCLR0] = (1 << pin);
		sleep(1);
	}

	munmap(gpio_map, BLOCK_SIZE);
	close(mem_fd);
	return 0;
}
