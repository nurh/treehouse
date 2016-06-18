#include<types.h>
#include<io.h>
#include<display.h>
#include<string.h>

struct op_console_t op_con;

void op_set_bg_color(enum vga_color c)
{
	op_con.background = (uint8_t)c;	
}

void op_set_fg_color(enum vga_color c)
{
	op_con.foreground = (uint8_t)c;	
}

void op_init_console(void)
{
	op_con.background = COLOR_BLACK;
	op_con.foreground = COLOR_WHITE;
	op_con.offset = 0;
	memset((void *)op_con.buf, 0, TEXTMODE_OFFSET_MAX);
}

uint16_t op_increment_cursor_pos(void)
{
	op_con.offset++;
	
	if(op_con.offset%TEXTMODE_OFFSET_MAX == 0) {
		op_move_buffer_up_one_line();
		op_con.offset = TEXTMODE_LAST_LINE_START_POS;		
	}

	return op_con.offset;
}

void op_putc(const uint8_t c)
{
	op_increment_cursor_pos();
	op_con.buf[op_con.offset] = c;
	op_write_buf_to_screen();
}

void op_move_buffer_up_one_line(void)
{
	memmove((void *)op_con.buf, (void *)&op_con.buf[TEXTMODE_LINE_SIZE], TEXTMODE_OFFSET_MAX-TEXTMODE_LINE_SIZE); /* move the buffer up */
	memset((void *)&op_con.buf[TEXTMODE_LAST_LINE_START_POS], 0, TEXTMODE_LINE_SIZE); /* blank last line */
}

void op_write_buf_to_screen(void)
{
	size_t i;
	volatile uint16_t *video = (volatile uint16_t *)VGABASEADDR;
	
	uint16_t color = (get_character_color(op_con.foreground, op_con.background) << 8);

	for(i=0;i<TEXTMODE_OFFSET_MAX;i++) {
		video[i] = color | op_con.buf[i];
	}	
}
