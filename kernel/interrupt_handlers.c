#include <panic.h>
#include <interrupt_handlers.h>

void default_interrupt_handler(void)
{
	panic("Interrupt detected but no handlers work yet.");
}
