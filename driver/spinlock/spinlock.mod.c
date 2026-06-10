#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x5e505530, "kthread_should_stop" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x0571dc46, "kthread_stop" },
	{ 0x9346b6c5, "gpio_to_desc" },
	{ 0xd2e1e487, "gpiod_set_raw_value" },
	{ 0xebe5da4a, "gpio_free" },
	{ 0x5403c125, "__init_waitqueue_head" },
	{ 0x76a97ac1, "gpio_request" },
	{ 0xd2e1e487, "gpiod_direction_output_raw" },
	{ 0x7f79e79a, "kthread_create_on_node" },
	{ 0x85960750, "wake_up_process" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0xf46d5bf3, "mutex_lock" },
	{ 0xf46d5bf3, "mutex_unlock" },
	{ 0xe1e1f979, "_raw_spin_lock_irqsave" },
	{ 0x81a1a811, "_raw_spin_unlock_irqrestore" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0x7a5ffe84, "init_wait_entry" },
	{ 0xd272d446, "schedule" },
	{ 0x0db8d68d, "prepare_to_wait_event" },
	{ 0xc87f4bab, "finish_wait" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xd272d446, "__fentry__" },
	{ 0x67628f51, "msleep" },
	{ 0xe8213e80, "_printk" },
	{ 0x16ab4215, "__wake_up" },
	{ 0xbebe66ff, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x5e505530,
	0xd272d446,
	0x0571dc46,
	0x9346b6c5,
	0xd2e1e487,
	0xebe5da4a,
	0x5403c125,
	0x76a97ac1,
	0xd2e1e487,
	0x7f79e79a,
	0x85960750,
	0xbd03ed67,
	0xf46d5bf3,
	0xf46d5bf3,
	0xe1e1f979,
	0x81a1a811,
	0x7851be11,
	0x7a5ffe84,
	0xd272d446,
	0x0db8d68d,
	0xc87f4bab,
	0xd272d446,
	0xd272d446,
	0x67628f51,
	0xe8213e80,
	0x16ab4215,
	0xbebe66ff,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"kthread_should_stop\0"
	"__x86_return_thunk\0"
	"kthread_stop\0"
	"gpio_to_desc\0"
	"gpiod_set_raw_value\0"
	"gpio_free\0"
	"__init_waitqueue_head\0"
	"gpio_request\0"
	"gpiod_direction_output_raw\0"
	"kthread_create_on_node\0"
	"wake_up_process\0"
	"__ref_stack_chk_guard\0"
	"mutex_lock\0"
	"mutex_unlock\0"
	"_raw_spin_lock_irqsave\0"
	"_raw_spin_unlock_irqrestore\0"
	"__SCT__might_resched\0"
	"init_wait_entry\0"
	"schedule\0"
	"prepare_to_wait_event\0"
	"finish_wait\0"
	"__stack_chk_fail\0"
	"__fentry__\0"
	"msleep\0"
	"_printk\0"
	"__wake_up\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B3EB950ACF13B60342301CD");
