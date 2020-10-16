#include <types.h>
#include <io.h>
#include <display.h>
#include <panic.h>
#include <cpu.h>

gdt_entry_t gdt[3];

void init_gdt(void)
{

	build_gdt_entry(&gdt[0], 0x0, 0x0, 0x0, 0x0);
	build_gdt_entry(&gdt[1], 0x0, 0xFFFFFFFF, (P_SEGMENT_PRESENT | DPL_RING_ZERO | S_CODE_OR_DATA_SEGMENT | TYPE_CODE_EXECUTE_READ), (G_4K_SEGMENTS | DB_32BIT_DEFAULT));
	build_gdt_entry(&gdt[2], 0x0, 0xFFFFFFFF, (P_SEGMENT_PRESENT | DPL_RING_ZERO | S_CODE_OR_DATA_SEGMENT | TYPE_DATA_READ_WRITE), (G_4K_SEGMENTS | DB_32BIT_DEFAULT));

	set_gdt((void *)gdt, sizeof(gdt));
}


int kernel_main() 
{
	init_gdt();

	op_init_console();
	op_set_fg_color(COLOR_CYAN);

	printk("Hello world! This is the treehouse!");

	return 0xDEADBEEF;
}
