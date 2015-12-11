#include <types.h>
#include <io.h>

int kernel_main() {

	clear_console();

	print_char('H', 37, 12, COLOR_LIGHT_RED, COLOR_BLACK);
	print_char('e', 38, 12, COLOR_LIGHT_CYAN, COLOR_BLACK);
	print_char('l', 39, 12, COLOR_GREEN, COLOR_BLACK);
	print_char('l', 40, 12, COLOR_BROWN, COLOR_BLACK);
	print_char('o', 41, 12, COLOR_LIGHT_GREEN, COLOR_BLACK);

	return 0xDEADBEEF;
}
