#include <io.h>

int kernel_main() {
	printk_early(2, "Hello treehouse!                                        ");

	return 0xDEADBEEF;
}
