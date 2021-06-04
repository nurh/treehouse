.global isr_wrapper_default

.align 4

isr_wrapper_default:
/* 
	We need to use EBX as a scratch register so we'll save its contents first,
	then we'll stick our original stack pointer in EBX.
*/

	push %ebx
	movl %esp, %ebx

/*
	This shifts the stack pointer to a 16b boundary, which is required for
	stack alignment.
*/
	and %esp, 0xfffffff0

/*
       This will push 4 bytes of zeros as padding. The struct should be 76 bytes,
       which is not a multiple of 16 so it won't line up right. Adding 4 more bytes
       makes it an even 80 (16*5).
*/
	pushl $0x0
	push $0x0
	push $0x20

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
	
	movl %ebx, %esp
	pop %ebx

	iret
