#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/init.h>
 
static int __init simple_driver_init(void)

{

    printk(KERN_INFO "Simple Driver: Module Inserted\n");

    return 0;

}
 
static void __exit simple_driver_exit(void)

{

    printk(KERN_INFO "Simple Driver: Module Removed\n");

}
 
module_init(simple_driver_init);

module_exit(simple_driver_exit);
 
MODULE_LICENSE("GPL");

MODULE_AUTHOR("Prashant");

MODULE_DESCRIPTION("Simple Linux Kernel Driver");
 
