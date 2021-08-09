#include <types.h>
#include <panic.h>
#include <io.h>
#include <cpu.h>
#include <timer.h>

/* Needs to be run with disabled interrupts */

void set_pit_count(uint16_t count) {
 
	outb(PIT_CHAN0_PORT,count&0xFF); /* Low byte */
	outb(PIT_CHAN0_PORT,(count&0xFF00)>>8); /* High byte */

	return;
}

void set_pit_cmd(uint8_t cmd) {
	outb(PIT_CMD_PORT, cmd);

	return;
}
