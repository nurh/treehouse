#include <types.h>
#include <io.h>
#include <display.h>

int kernel_main() 
{
	op_init_console();
	int i;

	for(i=0;i<100;i++) {
		printk("Hello treehouse. Build %s.", "Blah");
	}


	return 0xDEADBEEF;
}
