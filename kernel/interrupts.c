#include <types.h>
#include <cpu.h>
#include <panic.h>
#include <interrupts.h>
#include <scheduler.h>
#include <io.h>

void pic_init(void)
{
	uint8_t pic1mask, pic2mask;
 
	pic1mask = inb(PIC1DATA);
	pic2mask = inb(PIC2DATA);
 
	outb(PIC1CMD, 0x11);
	io_wait();
	outb(PIC2CMD, 0x11);
	io_wait();

	outb(PIC1DATA, 0x20);
	io_wait();
	outb(PIC2DATA, 0x70);
	io_wait();

	outb(PIC1DATA, 0x04);
	io_wait();
	outb(PIC2DATA, 0x02);
	io_wait();
 
	outb(PIC1DATA, 0x01);
	io_wait();
	outb(PIC2DATA, 0x01);
	io_wait();
 
	outb(PIC1DATA, pic1mask);
	outb(PIC2DATA, pic2mask);
}


void default_interrupt_handler(registers_t regs)
{
	printk("Interrupt detected!\n");

	if(regs.int_no == 0x20) {
		schedule();
	}
}
