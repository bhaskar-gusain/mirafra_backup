#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/input.h>

/* Kernel GPIO numbers from /sys/kernel/debug/gpio */
#define OUTPUT_GPIO_NUM   530          /* BCM18 = chip base 512 + 18 */
#define GPIO_VALUE_PATH   "/sys/class/gpio/gpio530/value"

static void pulse_gpio(void)
{
    int fd = open(GPIO_VALUE_PATH, O_WRONLY);
    if (fd < 0) {
        perror("open gpio value");
        return;
    }
    write(fd, "1", 1);   /* rising edge → triggers interrupt on GPIO17 */
    usleep(5000);         /* 5 ms pulse width                           */
    write(fd, "0", 1);   /* back low, ready for next pulse              */
    close(fd);
}

int main(int argc, char *argv[])
{
    const char *evdev = (argc > 1) ? argv[1] : "/dev/input/event2";
    struct input_event ev;
    int fd;

    fd = open(evdev, O_RDONLY);
    if (fd < 0) {
        perror("open evdev");
        fprintf(stderr, "Usage: %s /dev/input/eventX\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Listening on %s\n", evdev);
    printf("Press any key → GPIO pulse → IRQ fires → check dmesg\n\n");

    while (read(fd, &ev, sizeof(ev)) == sizeof(ev)) {

        /* EV_KEY + value 1 = key press (not repeat=2, not release=0) */
        if (ev.type == EV_KEY && ev.value == 1) {
            printf("Key code %-4d → pulsing GPIO18 → IRQ on GPIO17\n",
                   ev.code);
            fflush(stdout);
            pulse_gpio();
        }
    }

    close(fd);
    return EXIT_SUCCESS;
}
