.global isr_wrapper_default

.align 4

isr_wrapper_default:

	push 0x0
	push 0x0
	pushal
	push %gs
	push %fs
	push %es
	push %ds
	cld
	call default_interrupt_handler
	pop %ds
	pop %es
	pop %fs
	pop %gs
	popal
	add $8, %esp
	iret
