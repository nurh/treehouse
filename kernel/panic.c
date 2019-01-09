#include <types.h>
#include <io.h>
#include <display.h>
#include <panic.h>

void panic(char * msg)
{
	printk("Kernel panic: %s. System halted", msg);	

	halt();

	__builtin_unreachable();
}
