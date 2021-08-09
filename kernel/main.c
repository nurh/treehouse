#include <types.h>
#include <io.h>
#include <display.h>
#include <panic.h>
#include <cpu.h>
#include <interrupts.h>
#include <timer.h>

gdt_entry_t gdt[3];
idt_entry_t idt[256];

int kernel_main() 
{
	disable_interrupts();

	init_gdt();
	reload_segments();
	init_idt();
	pic_init();

	/* Hardcoded values for now */
	set_pit_cmd(0x34);
	set_pit_count(0x174E);

	enable_interrupts();

	op_init_console();
	op_set_fg_color(COLOR_CYAN);

	printk("Hello world!\nThis is the treehouse!");

	while(1) {
		// kernel runs la di da
	}

	return 0xDEADBEEF;
}
