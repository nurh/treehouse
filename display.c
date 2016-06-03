#include<types.h>
#include<io.h>

void print_char(const uint8_t c, const uint16_t x, const uint16_t y, enum vga_color foreground, enum vga_color background)
{
	uint16_t offset = (y * 80 + x);
	volatile uint16_t *video = (volatile uint16_t *)VGABASEADDR + offset;

	*video = (get_character_color(foreground, background) << 8) | c;
}


/* Assumes textmode */

void clear_console(void)
{
	size_t x, y;

	for(y=0;y<25;y++) {
		for(x=0;x<80;x++) {
			print_char(' ', x, y, COLOR_BLACK, COLOR_BLACK);
		}
	}
}
