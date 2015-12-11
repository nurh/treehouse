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

static inline uint8_t get_character_color(enum vga_color foreground, enum vga_color background)
{
	return (background << 4) | (foreground & 0x0f);
}

void print_char(const uint8_t c, const uint16_t x, const uint16_t y, enum vga_color foreground, enum vga_color background);

void clear_console(void);

void printk_early(int colour, const char *string);

#define VGABASEADDR 0xb8000
