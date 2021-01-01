#ifndef __TREEHOUSE_IO_H
#define __TREEHOUSE_IO_H

/* VGA stuff */

#define VGABASEADDR 0xb8000
#define TEXTMODE_OFFSET_MAX 2000 /* 80x25 */
#define TEXTMODE_LINE_SIZE 80
#define TEXTMODE_LAST_LINE_START_POS 1920 /* 2000 - TEXTMODE_LINE_SIZE */

/* PIC stuff */

#define PIC1CMD 0x20
#define PIC2CMD 0xA0
#define PIC1DATA 0x21
#define PIC2DATA 0xA1


enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

struct op_console_t {
	uint8_t foreground;
	uint8_t background;
	uint16_t offset;
	uint8_t buf[TEXTMODE_OFFSET_MAX]; 
};

static inline uint8_t get_character_color(enum vga_color foreground, enum vga_color background)
{
	return (background << 4) | (foreground & 0x0f);
}


static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

static inline void io_wait(void)
{
    asm volatile ( "jmp 1f\n\t"
                   "1:jmp 2f\n\t"
                   "2:" );
}

void clear_console(void);

void put_char(char c);
void put_int(int x);
void put_hex(int x);
void put_string(char * s);
void printk(const char * fmt, ...);


#endif /* __TREEHOUSE_IO_H */
