.global isr_wrapper_default

.align 4

isr_wrapper_default:
	pushal
	cld
	call default_interrupt_handler
	popal
	iret
