#include <linux/module.h>
#include <linux/gpio.h>           /* gpio_request, gpio_free, gpio_to_desc */
#include <linux/gpio/consumer.h>  /* gpiod_direction_input, gpiod_to_irq   */
#include <linux/interrupt.h>
#include <linux/irq.h>            /* irq_set_irq_type, IRQ_TYPE_EDGE_RISING */

#define GPIO_NUM 529

static struct gpio_desc *gpio_desc_17;
static int irq_number;

static irqreturn_t irq_demo_isr(int irq, void *dev_id)
{
	pr_info("irq_demo: interrupt on GPIO %d\n", GPIO_NUM);
	return IRQ_HANDLED;
}

static int __init irq_demo_init(void)
{
	int ret;

	pr_info("irq_demo: init\n");

	/* ── Step 1: claim the GPIO (legacy claim, still exported in 6.12) ── */
	ret = gpio_request(GPIO_NUM, "irq_demo_gpio17");
	if (ret) {
		pr_err("irq_demo: gpio_request(%d) failed: %d\n", GPIO_NUM, ret);
		return ret;
	}

	/* ── Step 2: get descriptor for modern API calls ── */
	gpio_desc_17 = gpio_to_desc(GPIO_NUM);
	if (!gpio_desc_17) {
		pr_err("irq_demo: gpio_to_desc(%d) failed\n", GPIO_NUM);
		ret = -EINVAL;
		goto err_free_gpio;
	}

	/* ── Step 3: set direction via descriptor ── */
	ret = gpiod_direction_input(gpio_desc_17);
	if (ret) {
		pr_err("irq_demo: gpiod_direction_input failed: %d\n", ret);
		goto err_free_gpio;
	}

	/* ── Step 4: get IRQ number via descriptor ── */
	irq_number = gpiod_to_irq(gpio_desc_17);
	if (irq_number < 0) {
		pr_err("irq_demo: gpiod_to_irq failed: %d\n", irq_number);
		ret = irq_number;
		goto err_free_gpio;
	}
	pr_info("irq_demo: IRQ number = %d\n", irq_number);

	/* ── Step 5: set trigger type BEFORE request_irq ──
	 *
	 * Passing IRQF_TRIGGER_RISING to request_irq returns -EINVAL on
	 * kernel 6.x / pinctrl-bcm2835 because the trigger is owned by
	 * the pinctrl layer. Configure it separately first, then call
	 * request_irq with 0 for flags.
	 */
	ret = irq_set_irq_type(irq_number, IRQ_TYPE_EDGE_RISING);
	if (ret) {
		pr_err("irq_demo: irq_set_irq_type failed: %d\n", ret);
		goto err_free_gpio;
	}

	/* ── Step 6: register handler — no IRQF_TRIGGER_* flags ── */
	ret = request_irq(irq_number,
			irq_demo_isr,
			0,              /* ← 0, not IRQF_TRIGGER_RISING */
			"irq_demo",
			NULL);
	if (ret) {
		pr_err("irq_demo: request_irq failed: %d\n", ret);
		goto err_free_gpio;
	}

	pr_info("irq_demo: registered successfully\n");
	return 0;

err_free_gpio:
	gpio_free(GPIO_NUM);   /* pairs with gpio_request above */
	return ret;
}

static void __exit irq_demo_exit(void)
{
	free_irq(irq_number, NULL);
	gpio_free(GPIO_NUM);
	pr_info("irq_demo: removed\n");
}

module_init(irq_demo_init);
module_exit(irq_demo_exit);
MODULE_LICENSE("GPL");
