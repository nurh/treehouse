.global isr_wrapper_default

.align 4

isr_wrapper_default:
.func isr_wrapper_default
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
       The struct should be 76 bytes, which is not a multiple of 16 but we need to
       leave 4 bytes for the return address push, which will make it an even 80.
*/

	push $0x0
	push $0x20

	pushal
	push %gs
	push %fs
	push %es
	push %ds
	cld

/* TODO: may need to load real segment registers here because we don't trust userspace. */

	call default_interrupt_handler

	mov $0x20, %al
	outb %al, $0x20

	pop %ds
	pop %es
	pop %fs
	pop %gs
	popal
	
	movl %ebx, %esp
	pop %ebx

	iret
.endfunc 
.size isr_wrapper_default, . - isr_wrapper_default
