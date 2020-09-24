#include <types.h>
#include <io.h>
#include <display.h>
#include <panic.h>

int kernel_main() 
{
	op_init_console();
	op_set_fg_color(COLOR_CYAN);

	printk("Hello world! This is the treehouse!");

	return 0xDEADBEEF;
}
