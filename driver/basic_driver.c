#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init basic_init(void){
	printk(KERN_INFO "BASIC DRIVER LOADED");
	return 0;
}
static void __exit basic_exit(void){
        printk(KERN_INFO "BASIC DRIVER EXIT");
}

module_init(basic_init);
module_exit(basic_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bhaskar");
MODULE_DESCRIPTION("MY BASIC DRIVER");

