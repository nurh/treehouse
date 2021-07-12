#include <types.h>
#include <io.h>
#include <display.h>
#include <panic.h>
#include <cpu.h>
#include <interrupts.h>

gdt_entry_t gdt[3];
idt_entry_t idt[256];

int kernel_main() 
{
	disable_interrupts();

	init_gdt();
	reload_segments();
	init_idt();
	pic_init();

	enable_interrupts();

	op_init_console();
	op_set_fg_color(COLOR_CYAN);

	printk("Hello world!\nThis is the treehouse!");

	asm volatile ("int $0x20");

	asm volatile ("int $0x20");

	asm volatile ("int $0x20");

	return 0xDEADBEEF;
}
