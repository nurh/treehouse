.global isr_wrapper_default

.align 4

isr_wrapper_default:
/* 
	We need to use EAX as a scratch register so we'll save its contents first,
	then we'll stick our original stack pointer in EAX.
*/

	push %eax
	movl %esp, %eax

/*
	This shifts the stack pointer to a 16b boundary, which is required for
	stack alignment.
*/
	and %esp, 0xfffffff0

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
