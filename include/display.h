#include <io.h>

void op_init_console(void);
void op_set_bg_color(enum vga_color c);
void op_set_fg_color(enum vga_color c);
uint16_t op_increment_cursor_pos(void);
void op_putc(const uint8_t c);
void op_move_buffer_up_one_line(void);
void op_write_buf_to_screen(void);
