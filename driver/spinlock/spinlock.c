#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/init.h>

#include <linux/gpio.h>

#include <linux/kthread.h>

#include <linux/delay.h>

#include <linux/mutex.h>

#include <linux/spinlock.h>

#include <linux/wait.h>

#include <linux/atomic.h>

#define GPIO_LED 17

static struct task_struct *led_thread;

static struct task_struct *event_thread;

/* Shared resource */

static int shared_counter;

/* Synchronization primitives */

static DEFINE_MUTEX(counter_mutex);

static spinlock_t counter_spinlock;

static wait_queue_head_t my_waitqueue;

static atomic_t event_flag = ATOMIC_INIT(0);

static int thread_condition;

/* ---------------------------------------- */

/* LED Thread                               */

/* ---------------------------------------- */

static int led_thread_fn(void *data)

{

	unsigned long flags;

	while (!kthread_should_stop()) {

		/*

		 * Sleep until event occurs

*/

		wait_event_interruptible(

				my_waitqueue,

				atomic_read(&event_flag));

		/*

		 * Clear event

*/

		atomic_set(&event_flag, 0);

		/*

		 * Mutex Protection

*/

		mutex_lock(&counter_mutex);

		shared_counter++;

		pr_info("LED Thread: shared_counter = %d\n",

				shared_counter);

		mutex_unlock(&counter_mutex);

		/*

		 * Spinlock Example

*/

		spin_lock_irqsave(&counter_spinlock, flags);

		gpio_set_value(GPIO_LED, 1);

		spin_unlock_irqrestore(&counter_spinlock, flags);

		msleep(500);

		spin_lock_irqsave(&counter_spinlock, flags);

		gpio_set_value(GPIO_LED, 0);

		spin_unlock_irqrestore(&counter_spinlock, flags);

		msleep(500);

	}

	return 0;

}

/* ---------------------------------------- */

/* Event Generator Thread                   */

/* ---------------------------------------- */

static int event_thread_fn(void *data)

{

	while (!kthread_should_stop()) {

		msleep(2000);

		pr_info("Event Thread: Triggering event\n");

		/*

		 * Signal event

*/

		atomic_set(&event_flag, 1);

		/*

		 * Wake sleeping thread

*/

		wake_up_interruptible(&my_waitqueue);

	}

	return 0;

}

/* ---------------------------------------- */

/* Driver Init                              */

/* ---------------------------------------- */

static int __init bcm2711_sync_init(void)

{

	int ret;

	pr_info("BCM2711 Sync Driver Init\n");

	/*

	 * Initialize synchronization primitives

*/

	spin_lock_init(&counter_spinlock);

	init_waitqueue_head(&my_waitqueue);

	/*

	 * Request GPIO

*/

	ret = gpio_request(GPIO_LED, "gpio_led");

	if (ret) {

		pr_err("GPIO request failed\n");

		return ret;

	}

	gpio_direction_output(GPIO_LED, 0);

	/*

	 * Create LED thread

*/

	led_thread = kthread_run(

			led_thread_fn,

			NULL,

			"led_thread");

	if (IS_ERR(led_thread)) {

		pr_err("Unable to create LED thread\n");

		gpio_free(GPIO_LED);

		return PTR_ERR(led_thread);

	}

	/*

	 * Create Event thread

*/

	event_thread = kthread_run(

			event_thread_fn,

			NULL,

			"event_thread");

	if (IS_ERR(event_thread)) {

		kthread_stop(led_thread);

		gpio_free(GPIO_LED);

		return PTR_ERR(event_thread);

	}

	pr_info("Driver loaded successfully\n");

	return 0;

}

/* ---------------------------------------- */

/* Driver Exit                              */

/* ---------------------------------------- */

static void __exit bcm2711_sync_exit(void)

{

	pr_info("BCM2711 Sync Driver Exit\n");

	if (led_thread)

		kthread_stop(led_thread);

	if (event_thread)

		kthread_stop(event_thread);

	gpio_set_value(GPIO_LED, 0);

	gpio_free(GPIO_LED);

}

module_init(bcm2711_sync_init);

module_exit(bcm2711_sync_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Prashant");

MODULE_DESCRIPTION("BCM2711 Synchronization Driver Example");

